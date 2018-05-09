project(Concept)
cmake_minimum_required(VERSION 2.8.12)

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

# Initial Conan setup
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()
conan_basic_setup()

# File generation
option(FOO_ENABLE "Enable Foo" ON)
if(FOO_ENABLE)
  set(FOO_STRING "foo")
endif()

# Code Generation
file(GLOB_RECURSE ENGINE_IN_FILES "${CMAKE_SOURCE_DIR}/Engine/*.in")
foreach(IN_FILE IN ITEMS ${ENGINE_IN_FILES})
	string(REPLACE ".in" "" FINAL "${IN_FILE}")
	message("Generating ${FINAL}")
	configure_file("${IN_FILE}" "${FINAL}" @ONLY)
endforeach()

# Source file gathering
file(GLOB_RECURSE ENGINE_SOURCES "${CMAKE_SOURCE_DIR}/Engine/*.cpp" "${CMAKE_SOURCE_DIR}/Engine/*.c" "${CMAKE_SOURCE_DIR}/Engine/*.hpp" "${CMAKE_SOURCE_DIR}/Engine/*.h")
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/Source/*.cpp" "${CMAKE_SOURCE_DIR}/Source/*.c" "${CMAKE_SOURCE_DIR}/Source/*.hpp" "${CMAKE_SOURCE_DIR}/Source/*.h")

# Create executable
add_executable (concept ${ENGINE_SOURCES} ${PROJECT_SOURCES})

# Link external libs
target_link_libraries(concept ${CONAN_LIBS})

# Add include directories
target_include_directories(concept PRIVATE ${CMAKE_SOURCE_DIR})

# Source group generation for IDEs
foreach(SOURCE IN ITEMS ${PROJECT_SOURCES} ${ENGINE_SOURCES})
    get_filename_component(SOURCE_PATH "${SOURCE}" PATH)
    file(RELATIVE_PATH SOURCE_PATH_REL "${CMAKE_SOURCE_DIR}" "${SOURCE_PATH}")
    string(REPLACE "/" "\\" GROUP_PATH "${SOURCE_PATH_REL}")
    source_group("${GROUP_PATH}" FILES "${SOURCE}")
endforeach()