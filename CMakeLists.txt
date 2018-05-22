project(Concept)
cmake_minimum_required(VERSION 2.8.12)

# Will make the .dll's also generate here
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_definitions("-std=c++11")
set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/Resources")

if(MSVC)
	set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /experimental:external /external:anglebrackets /external:W0 /Wall /GR /EHsc")
	if(NOT ${CMAKE_BUILD_TYPE} STREQUAL "Release")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /MTd")
	endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ansi -pedantic")
endif()
message("CMAKE_CXX_FLAGS -> ${CMAKE_CXX_FLAGS}")

set(SDL_STATIC OFF CACHE BOOL "Build a static version of the library")
add_subdirectory("Dependencies/SDL2" "${CMAKE_BINARY_DIR}/SDL2")
set(SDL_INCLUDE_DIRS "${SDL2_BINARY_DIR}/include" "${SDL2_SOURCE_DIR}/include")
set(SDL_LIBS SDL2main SDL2)

# add_subdirectory("Engine/cmake")
# add_subdirectory("Game/cmake")

# Create executable
add_executable(Concept "main.cpp")

target_include_directories(Concept 
    PUBLIC
    "${SDL_INCLUDE_DIRS}"
)

# Link external libs
target_link_libraries(Concept 
    PUBLIC
    ${SDL_LIBS}
)