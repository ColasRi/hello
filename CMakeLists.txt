cmake_minimum_required(VERSION 3.9.0)
project(hello_test)

include_directories(include)
file(GLOB SOURCES "src/*.c*")

add_executable(hello ${SOURCES})
