cmake_minimum_required(VERSION 3.16.0)
project(sd_engine VERSION 0.0 LANGUAGES CXX)
 
# VARIABLES
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
file(GLOB_RECURSE source_files "sde/*.cpp" "sde/*.hpp")

# LIBRARIES
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/glfw)

# TARGET
add_library(sd_engine SHARED ${source_files})

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_definitions(sd_engine PRIVATE SD_LINUX)
else()
	message(FATAL_ERROR "system not supported")
endif()

target_include_directories(sd_engine
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
)

target_link_directories(sd_engine
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/src
)

target_link_libraries(sd_engine glfw)
