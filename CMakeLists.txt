cmake_minimum_required(VERSION 3.16)
project(mincontracts
        VERSION 1.0.0
        DESCRIPTION "Minimal contract support library"
        LANGUAGES CXX)

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

set(PROJECT_HEADER_PATH "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}")
set(PROJECT_HEADERS
    ${PROJECT_HEADER_PATH}/mincontracts.hpp)

add_library(${PROJECT_NAME} INTERFACE
            ${PROJECT_HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES
                      PUBLIC_HEADER ${PROJECT_HEADERS})

target_include_directories(${PROJECT_NAME} INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}include/mincontracts>
                           #$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include/mincontracts>
                           )

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
        PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
        )

install(EXPORT ${PROJECT_NAME}Config
        FILE ${PROJECT_NAME}Config.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION lib/cmake/${PROJECT_NAME})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake" VERSION 1.0.0
    COMPATIBILITY SameMajorVersion)

install(
    FILES
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION lib/cmake/${PROJECT_NAME})

add_custom_target(
    uninstall
    COMMAND ${CMAKE_COMMAND} -E echo "Removing ${CMAKE_INSTALL_PREFIX}/lib/cmake/${PROJECT_NAME}"
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_INSTALL_PREFIX}/lib/cmake/${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E echo "Removing ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}"
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E echo "Removing ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}"
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}
)

enable_testing()
add_subdirectory(test)