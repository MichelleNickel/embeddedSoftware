cmake_minimum_required(VERSION 3.20)
project(Embedded_Software)

set(CMAKE_CXX_STANDARD 20)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES true)
add_subdirectory(lib/benchmark)

add_executable(Embedded_Software main.cpp
        ChipSequenzGenerator.cpp
        ChipSequenzGenerator.h
        config.h
        utils.h
        Analyser.cpp
        Analyser.h
        run.cpp
        run.h)

add_executable(Embedded_Software-Benchmark
        ChipSequenzGenerator.cpp
        ChipSequenzGenerator.h
        config.h
        utils.h
        Analyser.cpp
        Analyser.h
        benchmark.cpp
        run.cpp
        run.h)

target_link_libraries(Embedded_Software-Benchmark benchmark::benchmark)