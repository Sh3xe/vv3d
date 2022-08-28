cmake_minimum_required(VERSION 3.16.0)
project(vv3d_engine VERSION 1.3 LANGUAGES CXX)

# VARIABLES
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

file(GLOB_RECURSE SOURCE_FILES "source/*.cpp" "source/*.hpp")

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake_defines.hpp.in
	${CMAKE_CURRENT_SOURCE_DIR}/include/vv3d/cmake_defines.hpp
)

# LIBRARIES
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/glad)

# TARGET
add_library(vv3d_engine SHARED ${SOURCE_FILES})

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_definitions(vv3d_engine PRIVATE VV_LINUX)
else()
	message(FATAL_ERROR "system not supported")
endif()

target_include_directories(vv3d_engine
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include
)

target_link_directories(vv3d_engine
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/src
)

target_precompile_headers(vv3d_engine
	PRIVATE
	include/vv3d/defines.hpp
	include/vv3d/core/logger.hpp
	<iostream>
	<fstream>
	<sstream>
	<vector>
	<array>
	<map>
	<string>
	<initializer_list>
	<memory>
	<chrono>
	<thread>
	<mutex>
	<cassert>
)

target_link_libraries(vv3d_engine glfw glad)
