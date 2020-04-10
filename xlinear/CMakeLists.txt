file(GLOB_RECURSE files "src/*.cpp")

add_library(xlinear STATIC ${files})

target_include_directories(xlinear PUBLIC include)
