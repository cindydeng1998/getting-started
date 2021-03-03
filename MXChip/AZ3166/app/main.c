/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include <stdio.h>

#include "tx_api.h"

#include "board_init.h"
#include "cmsis_utils.h"
#include "screen.h"
#include "sntp_client.h"

#include "legacy/mqtt.h"
#include "nx_client.h"
#include "wwd_networking.h"

#include "azure_config.h"

// ulib imports
#include "az_ulib_ipc_api.h"
#include "az_ulib_result.h"
#include "cipher_v1i1.h"
#include "cipher_v2i1.h"
#include "my_consumer.h"
#include <stdio.h>

#define AZURE_THREAD_STACK_SIZE 4096
#define AZURE_THREAD_PRIORITY   4

TX_THREAD azure_thread;
ULONG azure_thread_stack[AZURE_THREAD_STACK_SIZE / sizeof(ULONG)];

static az_ulib_ipc ipc_handle;

void azure_thread_entry(ULONG parameter);
void tx_application_define(void* first_unused_memory);

int ipc_sample(void)
{
    az_result result;

    (void)printf("Start ipc_call_interface sample.\r\n\r\n");

    /*
    * Create the IPC. It shall be called at the very beginning of the application.
    * The IPC will prepare itself to receive interfaces.
    */
    if ((result = az_ulib_ipc_init(&ipc_handle)) != AZ_OK)
    {
    (void)printf("Initialize IPC failed with code %d.\r\n", result);
    }
    else
    {
    /* Publish cipher v1 with 1 key.
        * After this point anybody can call the cipher commands through IPC. */
    cipher_v1i1_create();
    (void)printf("\r\n");

    /* Consumer will use the math interface. */
    my_consumer_create();
    (void)printf("\r\n");

    ///* My consumer try to use math to add numbers. */
    my_consumer_do_cipher(0);
    my_consumer_do_cipher(1);
    (void)printf("\r\n");

    /* Unpublish cipher v1. After this point, any call to cipher will return
        * AZ_ERROR_ITEM_NOT_FOUND. */
    cipher_v1i1_destroy();
    (void)printf("\r\n");

    ///* My consumer try to use math to add numbers. */
    my_consumer_do_cipher(0);
    my_consumer_do_cipher(1);
    (void)printf("\r\n");

    /* Publish cipher v2 with 2 key.
        * After this point anybody can call the cipher commands through IPC. */
    cipher_v2i1_create();
    (void)printf("\r\n");

    ///* My consumer try to use math to add numbers. */
    my_consumer_do_cipher(0);
    my_consumer_do_cipher(1);
    (void)printf("\r\n");

    /* Unpublish cipher v2. After this point, any call to cipher will return
        * AZ_ERROR_ITEM_NOT_FOUND. */
    cipher_v2i1_destroy();
    (void)printf("\r\n");

    /* Consumer will stop to use the math interface. */
    my_consumer_destroy();
    (void)printf("\r\n");

    return 1;
}

void azure_thread_entry(ULONG parameter)
{
    UINT status;

    printf("Starting Azure thread\r\n\r\n");

    if (platform_init(WIFI_SSID, WIFI_PASSWORD, WIFI_MODE) != NX_SUCCESS)
    {
        printf("Failed to initialize platform.\r\n");
        return;
    }
    screen_print("WiFi ready", L0);

    // Start the SNTP client
    status = sntp_start();
    if (status != NX_SUCCESS)
    {
        printf("Failed to start the SNTP client (0x%02x)\r\n", status);
        return;
    }

    // Wait for an SNTP sync
    status = sntp_sync_wait();
    if (status != NX_SUCCESS)
    {
        printf("Failed to start sync SNTP time (0x%02x)\r\n", status);
        return;
    }
    screen_print("SNTP inited", L0);

    // call ulib sample
    status = ipc_sample();
    if(status == 1)
    {
        screen_print("IPC example success", L0);
    }

#ifdef ENABLE_LEGACY_MQTT
    if ((status = azure_iot_mqtt_entry(&nx_ip, &nx_pool[0], &nx_dns_client, sntp_time_get)))
#else
    if ((status = azure_iot_nx_client_entry(&nx_ip, &nx_pool[0], &nx_dns_client, sntp_time)))
#endif
    {
        printf("Failed to run Azure IoT (0x%04x)\r\n", status);
        return;
    }
}

void tx_application_define(void* first_unused_memory)
{
    systick_interval_set(TX_TIMER_TICKS_PER_SECOND);

    // Create Azure thread
    UINT status = tx_thread_create(&azure_thread,
        "Azure Thread",
        azure_thread_entry,
        0,
        azure_thread_stack,
        AZURE_THREAD_STACK_SIZE,
        AZURE_THREAD_PRIORITY,
        AZURE_THREAD_PRIORITY,
        TX_NO_TIME_SLICE,
        TX_AUTO_START);

    if (status != TX_SUCCESS)
    {
        printf("Azure IoT application failed, please restart\r\n");
    }
}

int main(void)
{
    // Initialise the board
    board_init();

    // Enter the ThreadX kernel
    tx_kernel_enter();

    return 0;
}
