cmake_minimum_required(VERSION 3.13)

# Initialize the SDK based on PICO_SDK_PATH
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(blink_project)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Create an executable for the blink project
add_executable(blink
    main.c
)

# Link the pico_stdlib and hardware_adc libraries
target_link_libraries(blink
    pico_stdlib    # Standard functions
    hardware_adc   # ADC functionality for reading analog values
)

# Enable USB output, disable UART output (optional, depending on your setup)
pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 0)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(blink)
