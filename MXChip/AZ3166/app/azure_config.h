/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#ifndef _AZURE_CONFIG_H
#define _AZURE_CONFIG_H

typedef enum
{
    None         = 0,
    WEP          = 1,
    WPA_PSK_TKIP = 2,
    WPA2_PSK_AES = 3
} WiFi_Mode;

// ----------------------------------------------------------------------------
// WiFi connection config
// ----------------------------------------------------------------------------
#define WIFI_SSID     "CindyPhone"
#define WIFI_PASSWORD "qazqwe123"
#define WIFI_MODE     WPA2_PSK_AES

// ----------------------------------------------------------------------------
// Azure IoT Dynamic Provisioning Service
//    Define this to use the DPS service, otherwise direct IoT Hub
// ----------------------------------------------------------------------------
//#define ENABLE_DPS

// ----------------------------------------------------------------------------
// Azure IoT DPS connection config
//    IOT_DPS_ID_SCOPE:        The DPS ID Scope
//    IOT_DPS_REGISTRATION_ID: The DPS device Registration Id
// ----------------------------------------------------------------------------
#define IOT_DPS_ID_SCOPE        ""
#define IOT_DPS_REGISTRATION_ID ""

// ----------------------------------------------------------------------------
// Azure IoT Hub Connection Transport
//    Define to use the legacy MQTT connection, else Azure RTOS SDK for Azure IoT
// ----------------------------------------------------------------------------
//#define ENABLE_LEGACY_MQTT

// ----------------------------------------------------------------------------
// Azure IoT DPS Self-Signed X509Certificate
//    Define this to connect to DPS or Iot Hub using a X509 certificate
// ----------------------------------------------------------------------------
//#define ENABLE_X509

// ----------------------------------------------------------------------------
// Azure IoT Hub connection config
//    IOT_HUB_HOSTNAME:  The Azure IoT Hub hostname
//    IOT_HUB_DEVICE_ID: The Azure IoT Hub device id
// ----------------------------------------------------------------------------
#define IOT_HUB_HOSTNAME  "cindy-hub.azure-devices.net"
#define IOT_HUB_DEVICE_ID "MXChip"

// ----------------------------------------------------------------------------
// Azure IoT device SAS key
//    The SAS key generated by configuring an IoT Hub device or DPS individual
//    enrollment
// ----------------------------------------------------------------------------
#define IOT_DEVICE_SAS_KEY "+/9NID6n48v1dHw6BBpDYo7v/9WG5vWQTnSyZMqgLeI="

#endif // _AZURE_CONFIG_H
