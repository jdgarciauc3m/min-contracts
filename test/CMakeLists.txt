find_package(GTest)

include_directories(../include)

add_executable(utest preconditions.cpp)
target_link_libraries(utest GTest::GTest GTest::Main)

gtest_discover_tests(utest)