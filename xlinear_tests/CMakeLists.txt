file(GLOB_RECURSE files "src/*.cpp")

add_executable(xlinear_tests ${files})
target_link_libraries(xlinear_tests PRIVATE xlinear)
