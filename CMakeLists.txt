cmake_minimum_required(VERSION 3.30)
project(data_structures_C)

set(CMAKE_CXX_STANDARD 20)

add_executable(data_structures_C main.cpp
        GRAPHS/adj_list_ud.c
        GRAPHS/adj_list.c
        HEAP/heap_pq.c)
