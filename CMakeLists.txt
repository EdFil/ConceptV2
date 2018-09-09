project(Concept)
cmake_minimum_required(VERSION 2.8.12)

# Configure CMake
set (CMAKE_CXX_STANDARD 11)

# Variable definitions
set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/Resources")

# CXX Flags
if(MSVC)
	set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /experimental:external /external:anglebrackets /external:W0 /Wall /GR /EHsc")
	if(NOT ${CMAKE_BUILD_TYPE} STREQUAL "Release")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /MTd")
	endif()
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ansi -pedantic")
endif()

add_subdirectory("dependencies/Engine")

# Create executable
add_executable(Concept "main.cpp")

# Link external libs
target_link_libraries(Concept 
    PRIVATE Engine_Static
)