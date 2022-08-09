cmake_minimum_required(VERSION 3.16.0)

project(sandbox)

file( GLOB_RECURSE source_files "src/*.hpp" "src/*.cpp" )

add_executable(sandbox ${source_files})

target_link_libraries(sandbox PUBLIC sd_engine)