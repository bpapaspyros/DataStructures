cmake_minimum_required(VERSION 2.6)

project(treeCeid)
SET(CMAKE_BUILD_TYPE Release)
# SET(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/src/)

file(GLOB_RECURSE SOURCE ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INCS ${PROJECT_SOURCE_DIR}/include/*.h)

# Extra compiler flags
add_definitions(-TEST=1)
add_definitions(-Wall)
add_definitions(-Wextra)
add_definitions(-std=c++0x)
if(CMAKE_BUILD_TYPE EQUAL "DEBUG")
	add_definitions(-g)
endif()


find_package(Graphviz)

IF (GRAPHVIZ_GVC_FOUND)
	IF (GRAPHVIZ_CGRAPH_FOUND)
		add_definitions(-DWITH_CGRAPH)
		add_executable(tree ${INCS} ${SOURCE} ${PROJECT_SOURCE_DIR}/src/main.cpp)
		target_link_libraries(tree ${GRAPHVIZ_CGRAPH_LIBRARY} ${GRAPHVIZ_GVC_LIBRARY})
	ELSE (GRAPHVIZ_CGRAPH_FOUND)
		IF (GRAPHVIZ_GRAPH_FOUND)
			add_executable(tree ${INCS} ${SOURCE} ${PROJECT_SOURCE_DIR}/src/main.cpp)
			target_link_libraries(tree ${GRAPHVIZ_CGRAPH_LIBRARY} ${GRAPHVIZ_GVC_LIBRARY})
		ENDIF (GRAPHVIZ_GRAPH_FOUND)
	ENDIF (GRAPHVIZ_CGRAPH_FOUND)
ENDIF (GRAPHVIZ_GVC_FOUND)