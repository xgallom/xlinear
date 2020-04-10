cmake_minimum_required(VERSION 3.15)
project(xlinear_tests)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE files "src/*.cpp")

add_executable(xlinear_tests ${files})
target_link_libraries(xlinear_tests PRIVATE xlinear)
