cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico_test C CXX ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(lib/BNO08x)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)

add_executable(pico_test
  ${SOURCES}
)

target_include_directories(pico_test PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(pico_test
    pico_stdlib
    hardware_i2c
    hardware_spi
    hardware_adc
    BNO08x_Pico_Library
)

pico_add_extra_outputs(pico_test)
