# set headers
set(header_path "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}")
set(header
    ${header_path}/mincontracts.hpp)

set(src mincontracts.cpp)

add_library(mincontracts ${header} ${src})
set_target_properties(${PROJECT_NAME} PROPERTIES
                      PUBLIC_HEADER "../include/${PROJECT_NAME}/mincontracts.hpp")

target_include_directories(${PROJECT_NAME} PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:include>
                           )

install(TARGETS ${PROJECT_NAME} EXPORT mincontractsConfig
        LIBRARY DESTINATION lib/${PROJECT_NAME}
        ARCHIVE DESTINATION lib/${PROJECT_NAME}
        RUNTIME DESTINATION bin/${PROJECT_NAME}
        PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
        PRIVATE_HEADER DESTINATION include/${PROJECT_NAME})

install(EXPORT mincontractsConfig
        FILE mincontractsConfig.cmake
        NAMESPACE mincontracts::
        DESTINATION lib/cmake/${PROJECT_NAME})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/mincontractsConfigVersion.cmake" VERSION 1.0.0
    COMPATIBILITY SameMajorVersion)

install(
    FILES
    "${CMAKE_BINARY_DIR}/mincontractsConfigVersion.cmake"
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