cmake_minimum_required(VERSION 3.16)
project(first_proj CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost 라이브러리를 찾을 수 없습니다. Boost를 설치하세요.")
endif()


find_package(GTest REQUIRED)

if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Google Test를 찾을 수 없습니다. Google Test를 설치하세요.")
endif()

enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")

# add_subdirectory(account)
# add_subdirectory(authentication)
# add_subdirectory(product)
# add_subdirectory(order)

add_subdirectory(ui/console)
add_subdirectory(thread)

add_executable(every_cpp_unit_test ${TEST_SOURCES})
target_link_libraries(every_cpp_unit_test PRIVATE ${GTEST_LIBRARIES} ${Boost_LIBRARIES} pthread)
#target_link_libraries(every_cpp_unit_test PRIVATE account authentication product order ${GTEST_LIBRARIES} ${Boost_LIBRARIES} pthread)

add_test(NAME every_cpp_unit_test COMMAND every_cpp_unit_test)
set_tests_properties(every_cpp_unit_test PROPERTIES FAIL_REGULAR_EXPRESSION ".*[Ff]ail.*")

add_executable(cpp_app main.cpp)
target_link_libraries(cpp_app ui_console thread_manager ${Boost_LIBRARIES} pthread)
#target_link_libraries(cpp_app account authentication product order ${Boost_LIBRARIES})
