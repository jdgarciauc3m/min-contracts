# set headers
set(header_path "${MINCONTRACTS_SOURCE_DIR}/include/mincontracts")
set(header ${header_path}/mincontracts.hpp)

set(src mincontracts.cpp)

add_library(mincontracts ${header} ${src})