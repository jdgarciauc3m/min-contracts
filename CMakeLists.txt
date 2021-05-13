cmake_minimum_required(VERSION 3.19)
project(min-contracts)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_subdirectory(test)