cmake_minimum_required(VERSION 3.15)
project(xlinear)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE files "src/*.cpp")

add_library(xlinear STATIC ${files})

target_include_directories(xlinear PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include")



option(XLINEAR_CFG_FLOATING_USE_ULP_COMPARE "Floating object use ULP compare" ON)

if(XLINEAR_CFG_FLOATING_USE_ULP_COMPARE)
    set(XLINEAR_CFG_FLOATING_ULP_MAX_COMPARE_DISTANCE 4)
endif()



file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/xlinear/config")
configure_file(config/floating.h include/xlinear/config/floating.h @ONLY)
