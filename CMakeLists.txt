cmake_minimum_required(VERSION 3.19)

project(aoc_2020 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -O3")

add_subdirectory(src)
