cmake_minimum_required(VERSION 3.15)
project(iot_lightweight_payload C)

set(CMAKE_C_STANDARD 99)

add_executable(iot_lightweight_payload main.c payload.c payload.h type.h)