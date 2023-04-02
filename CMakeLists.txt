cmake_minimum_required(VERSION 3.25)
project(DNA_RNA_Project CXX)

set(CMAKE_C_STANDARD 17)

include_directories(.)

add_executable(DNA_RNA_Project
        main.cpp
        app.cpp
        genome.cpp
        cell.cpp
        genome_factory.cpp
        cell_factory.cpp
        dna_utils.cpp)
