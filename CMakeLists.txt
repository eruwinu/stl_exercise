cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++1y -Wall -Werror")

project(stl_exer)

add_executable(1exe 1.duplicate_values.cpp)
add_executable(2exe 2.cheapest.cpp)
add_executable(3exe 3.even_odd.cpp)
add_executable(4exe 4.sum.cpp)
add_executable(5exe 5.percentiles.cpp)
add_executable(6exe 6.diff.cpp)
add_executable(7exe 7.slist.cpp)
add_executable(8exe 8.mastermind.cpp)
