cmake_minimum_required(VERSION 3.30)
project(Embedded_Software)

set(CMAKE_CXX_STANDARD 20)

add_executable(Embedded_Software main.cpp
        ChipSequenzGenerator.cpp
        ChipSequenzGenerator.h
        config.h)
