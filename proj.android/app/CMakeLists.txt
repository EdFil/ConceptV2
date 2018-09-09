cmake_minimum_required(VERSION 3.4.1)

set(RESOURCES_DIR "")

# SDL Dependency
set(SDL_SHARED ON CACHE BOOL "Build a shared version of the library")
set(SDL_STATIC OFF CACHE BOOL "Build a static version of the library")
add_subdirectory("${CMAKE_SOURCE_DIR}/../../dependencies/Engine/dependencies/SDL2" "${CMAKE_BINARY_DIR}/SDL2")
set(SDL_INCLUDE_DIRS "${SDL2_BINARY_DIR}/include" "${SDL2_SOURCE_DIR}/include")
set(SDL_LIBS SDL2 SDL2main)

message(STATUS "SDL2_BINARY_DIR -> ${SDL2_BINARY_DIR}")
message(STATUS "SDL_LIBS -> ${SDL_LIBS}")

add_library(main SHARED
    "src/main/jni/JNI.cpp"
    "src/main/jni/main.cpp")

# Include directotories
target_include_directories(main
    PUBLIC
    "${SDL_INCLUDE_DIRS}"
)

target_link_libraries(main ${SDL_LIBS})
