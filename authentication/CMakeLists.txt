project(my_tests)

set(TEST_HEADERS)
set(TEST_SOURCES first_test.cpp)

add_executable(my_tests ${TEST_HEADERS} ${TEST_SOURCES})

target_link_libraries(my_tests PRIVATE my_cpp_app account authentication product order ${GTEST_LIBRARIES} ${Boost_LIBRARIES} pthread)
