# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

# Define the cpu architecture for threadx
set(THREADX_ARCH "cortex_m4")
set(THREADX_TOOLCHAIN "gnu")

# Define ThreadX user configuration
set(TX_USER_FILE "${CMAKE_CURRENT_LIST_DIR}/threadx/tx_user.h" CACHE STRING "Enable TX user configuration")

# Define NetXDuo user configuration
set(NX_USER_FILE "${CMAKE_CURRENT_LIST_DIR}/netxduo/nx_user.h" CACHE STRING "Enable NX user configuration")
set(NXD_ENABLE_FILE_SERVERS OFF CACHE BOOL "Disable fileX dependency by netxduo")

add_subdirectory(${CORE_LIB_DIR}/threadx threadx)
add_subdirectory(${CORE_LIB_DIR}/netxduo netxduo)
add_subdirectory(${CORE_LIB_DIR}/azure-iot-preview/nx_cloud nx_cloud)
add_subdirectory(${CORE_LIB_DIR}/azure-iot-preview/azure_iot azure_iot)
add_subdirectory(${CORE_LIB_DIR}/jsmn jsmn)

# Bind the nx_cloud preview include into the existing netxduo
target_include_directories(netxduo 
    PUBLIC
        ${CORE_LIB_DIR}/azure-iot-preview/nx_cloud
)

add_subdirectory(stm32cubef4)
add_subdirectory(wiced_sdk)
