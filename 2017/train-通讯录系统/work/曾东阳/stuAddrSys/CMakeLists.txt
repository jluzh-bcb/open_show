cmake_minimum_required(VERSION 3.9)
project(stuAddrSys)

set(CMAKE_CXX_STANDARD 98)
set(SOURCE_FILES
        database.cpp
        main.cpp)
add_executable(stuAddrSys ${SOURCE_FILES})