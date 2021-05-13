find_package(GTest)

include_directories(../include)

add_executable(test preconditions.cpp)
target_link_libraries(test GTest::GTest GTest::Main)