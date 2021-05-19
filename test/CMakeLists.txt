find_package(GTest)

if(GTest_FOUND)

  option(${PROJECT_NAME}_TESTS "Enable unit testing" ON)
  if(${PROJECT_NAME}_TESTS)
    add_executable(utest preconditions.cpp postconditions.cpp assertions.cpp)
    target_link_libraries(utest mincontracts GTest::GTest GTest::Main)
    gtest_discover_tests(utest)
  endif()

endif(GTest_FOUND)