cmake_minimum_required(VERSION 3.19)
project(MINCONTRACTS)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  add_compile_options(/W3)
endif()

add_subdirectory(src)

enable_testing()
add_subdirectory(test)