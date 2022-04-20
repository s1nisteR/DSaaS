cmake_minimum_required(VERSION 3.22)
project(DSaaS)

set(CMAKE_CXX_STANDARD 20)

include_directories(include lib)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.74)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(DSaaS
        src/main.cpp)
target_link_libraries(DSaaS ${Boost_LIBRARIES})