cmake_minimum_required(VERSION 3.24)
project(GNL C)

set(CMAKE_C_STANDARD 99)

add_executable(GNL pacodir/get_next_line_utils.c pacodir/get_next_line.h
        pacodir/get_next_line.c
)
