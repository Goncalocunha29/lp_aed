cmake_minimum_required(VERSION 3.26)
project(projeto C)

set(CMAKE_C_STANDARD 99)

add_executable(projeto main.c
        projeto.c
        projeto.h)
