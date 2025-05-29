cmake_minimum_required(VERSION 3.20)
project(Embedded_Software)

set(CMAKE_CXX_STANDARD 20)

# Setze -O3 (Für Chrono und Benchmark-Framework)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Erzwinge Release-Modus
set(CMAKE_BUILD_TYPE Release)

add_executable(Embedded_Software 
        main.cpp
        ChipSequenzGenerator.cpp
        ChipSequenzGenerator.h
        config.h
        utils.h
        Analyser.cpp
        Analyser.h)
