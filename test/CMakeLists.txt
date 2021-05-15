find_package(GTest)

include_directories(../include)

add_executable(utest preconditions.cpp postconditions.cpp assertions.cpp)
target_link_libraries(utest mincontracts GTest::GTest GTest::Main)

gtest_discover_tests(utest)