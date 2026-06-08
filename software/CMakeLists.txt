cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_test C CXX ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(lib/BNO08x)


add_executable(pico_test
    src/main.cpp
    src/BNO080.cpp
    src/orientation.cpp
    src/MCP2515.cpp
    src/spi.cpp
)

target_include_directories(pico_test PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(pico_test
    pico_stdlib
    hardware_i2c
    hardware_spi
    BNO08x_Pico_Library
)

pico_add_extra_outputs(pico_test)
