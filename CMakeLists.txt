cmake_minimum_required(VERSION 3.29)
project(SystemProgramming C)

set(CMAKE_C_STANDARD 11)

add_executable(SystemProgramming
    root_folder/mastering-dsa/graph/adjacency_matrix.c
    root_folder/mastering-dsa/graph/edges_list.c
        root_folder/dynamic-memory/concat.c)
