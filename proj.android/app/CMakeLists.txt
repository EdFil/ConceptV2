cmake_minimum_required(VERSION 3.4.1)

set(RESOURCES_DIR "")

#add_subdirectory("${CMAKE_SOURCE_DIR}/../../Game/cmake" "${CMAKE_BINARY_DIR}/Game")

add_library(native-lib SHARED
    #"src/main/cpp/native-lib.cpp"
    "src/main/jni/sdlactivity.c")

#target_link_libraries(native-lib Game Engine)