cmake_minimum_required(VERSION 3.16)
project(first_proj CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(cpp_app main.cpp)
    target_link_libraries(cpp_app ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost 라이브러리를 찾을 수 없습니다. Boost를 설치하세요.")
endif()