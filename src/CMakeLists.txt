# set headers
set(header_path "${MINCONTRACTS_SOURCE_DIR}/include/mincontracts")
set(header
    ${header_path}/mincontracts.hpp)

set(src mincontracts.cpp)

add_library(mincontracts ${header} ${src})
target_include_directories(mincontracts PUBLIC
                           $<BUILD_INTERFACE:${MINCONTRACTS_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:${include_dest}>)

install(TARGETS mincontracts
        EXPORT mincontracts
        DESTINATION "${lib_dest}")
install(FILES ${header}
        DESTINATION "${include_dest}")
install(EXPORT mincontracts
        DESTINATION "${lib_dest}")
install(FILES ${MINCONTRACTS_SOURCE_DIR}/cmake/MinContracts-config.cmake
        DESTINATION "${cmake_dest}")

