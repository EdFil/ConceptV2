project(Concept)
cmake_minimum_required(VERSION 2.8.12)

add_definitions("-std=c++11 -Wall -ansi -pedantic -Wextra")

# Initial Conan setup
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()
conan_basic_setup()

# Source file gathering -> https://stackoverflow.com/questions/6921695/how-can-i-build-a-c-project-with-multiple-interdependent-subdirectories
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "src/*.h")
set (PROJECT_INCLUDE_DIRS "")
foreach (_headerFile ${PROJECT_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND PROJECT_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES PROJECT_INCLUDE_DIRS)

# Create executable
add_executable (concept ${PROJECT_SOURCES})

# Link external libs
target_link_libraries(concept ${CONAN_LIBS})

# Add include directories
target_include_directories(concept PRIVATE ${PROJECT_INCLUDE_DIRS})