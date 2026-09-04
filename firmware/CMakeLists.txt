cmake_minimum_required(VERSION 3.16)
project(modhw_firmware C)

option(MODHW_HOST_SIM "Build protocol registry as a host CLI" ON)

set(MODHW_SOURCES
    src/core/cape.c
    src/core/registry.c
    src/protocols/uart.c
    src/protocols/spi.c
    src/protocols/i2c.c
    src/protocols/jtag.c
    src/protocols/pin_scan.c
    src/protocols/subghz.c
    src/protocols/nfc.c
    src/capture/logic.c
    src/ui/display.c
    src/scripts/script_host.c
)

add_library(modhw_core STATIC ${MODHW_SOURCES})
target_include_directories(modhw_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MODHW_HOST_SIM)
    add_executable(modhw_sim src/main.c)
    target_link_libraries(modhw_sim PRIVATE modhw_core)
endif()
