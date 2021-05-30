find_package(GTest)

if(GTest_FOUND)

  option(${PROJECT_NAME}_TESTS "Enable unit testing" ON)
  if(${PROJECT_NAME}_TESTS)
    add_executable(utest preconditions.cpp postconditions.cpp assertions.cpp)
    target_link_libraries(utest GTest::GTest GTest::Main)
    target_include_directories(utest BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/include)
    gtest_discover_tests(utest)
  endif()

endif(GTest_FOUND)