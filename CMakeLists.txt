cmake_minimum_required(VERSION 3.1)
project(mmCommander_UART_SDCC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/cc1110-ext.h
    include/cc1111.h
    include/cc1111_vcom.h
    include/cc1111rf.h
    include/cc1111usb.h
    include/cc1111usbdebug.h
    include/dma.h
    include/global.h
    application.c
    cc1111_vcom.c
    cc1111_vcomdesc.c
    cc1111rf.c
    cc1111uart.c
    cc1111usb.c
    cc1111usbdebug.c
    dma.c
    global.c)

add_executable(mmCommander_UART_SDCC ${SOURCE_FILES})