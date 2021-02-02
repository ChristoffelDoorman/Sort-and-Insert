cmake_minimum_required(VERSION 3.13)
project(Assignment3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment3
        linked_list.c helpers.c helpers.h merge_sort.c merge_sort.h inserts.c inserts.h)
