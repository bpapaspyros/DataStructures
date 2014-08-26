cmake_minimum_required(VERSION 2.6)

project(sNsCeid)
SET(CMAKE_BUILD_TYPE Release)
# SET(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/src/)

# Extra compiler flags
add_definitions(-Wall)
add_definitions(-Wextra)
if(CMAKE_BUILD_TYPE EQUAL "DEBUG")
	add_definitions(-g)
endif()

file(GLOB_RECURSE SOURCE ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INCS ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable(sortNsearch ${INCS} ${SOURCE} ${PROJECT_SOURCE_DIR}/src/main.cpp)


