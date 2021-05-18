cmake_minimum_required(VERSION 3.19)
project(mincontracts)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  add_compile_options(/W3)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(include_dest "include/mincontracts")
set(lib_dest "lib/mincontracts/${CMAKE_BUILD_TYPE}")
set(cmake_dest "lib/cmake/mincontracts")
set(cmake_build_dest "${cmake_dest}/${CMAKE_BUILD_TYPE}")

add_subdirectory(src)

enable_testing()
add_subdirectory(test)



