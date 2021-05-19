# set headers
set(header_path "${mincontracts_SOURCE_DIR}/include/mincontracts")
set(header
    ${header_path}/mincontracts.hpp)

set(src mincontracts.cpp)

add_library(mincontracts ${header} ${src})
set_target_properties(mincontracts PROPERTIES
                      PUBLIC_HEADER "../include/mincontracts/mincontracts.hpp")

target_include_directories(mincontracts PUBLIC
                           $<BUILD_INTERFACE:${mincontracts_BINARY_DIR}/include>
                           $<BUILD_INTERFACE:${mincontracts_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:include>
                           )

install(TARGETS mincontracts EXPORT mincontractsConfig
        LIBRARY DESTINATION lib/mincontracts
        ARCHIVE DESTINATION lib/mincontracts
        RUNTIME DESTINATION bin/mincontracts
        PUBLIC_HEADER DESTINATION include/mincontracts
        PRIVATE_HEADER DESTINATION include/mincontracts)

install(EXPORT mincontractsConfig
        FILE mincontractsConfig.cmake
        NAMESPACE mincontracts::
        DESTINATION lib/cmake/mincontracts)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/mincontractsConfigVersion.cmake" VERSION 1.0.0
    COMPATIBILITY SameMajorVersion)

install(
    FILES
    "${CMAKE_BINARY_DIR}/mincontractsConfigVersion.cmake"
    DESTINATION lib/cmake/mincontracts)

add_custom_target(
    uninstall
    COMMAND ${CMAKE_COMMAND} -E echo "Removing ${CMAKE_INSTALL_PREFIX}/lib/cmake/mincontracts"
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_INSTALL_PREFIX}/lib/cmake/mincontracts
    COMMAND ${CMAKE_COMMAND} -E echo "Removing ${CMAKE_INSTALL_PREFIX}/lib/mincontracts"
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_INSTALL_PREFIX}/lib/mincontracts
    COMMAND ${CMAKE_COMMAND} -E echo "Removing ${CMAKE_INSTALL_PREFIX}/include/mincontracts"
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_INSTALL_PREFIX}/include/mincontracts
)