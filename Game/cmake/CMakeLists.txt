project(Game)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/../src")

# Code Generation
file(GLOB_RECURSE ENGINE_IN_FILES "${SOURCE_DIR}/*.in")
foreach(IN_FILE IN ITEMS ${ENGINE_IN_FILES})
	string(REPLACE ".in" "" FINAL "${IN_FILE}")
	message("Generating ${FINAL}")
	configure_file("${IN_FILE}" "${FINAL}" @ONLY)
endforeach()

# Source gathering
file(GLOB_RECURSE SOURCES 
    "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.c"
    "${SOURCE_DIR}/*.hpp" "${SOURCE_DIR}/*.h")

# Make library
add_library(Game STATIC ${SOURCES})

# Include directotories
target_include_directories(Game PUBLIC "${SOURCE_DIR}")

# Source group generation for IDEs
foreach(SOURCE IN ITEMS ${SOURCES})
    get_filename_component(SOURCE_PATH "${SOURCE}" PATH)
    file(RELATIVE_PATH SOURCE_PATH_REL "${SOURCE_DIR}" "${SOURCE_PATH}")
    string(REPLACE "/" "\\" GROUP_PATH "${SOURCE_PATH_REL}")
    source_group("${GROUP_PATH}" FILES "${SOURCE}")
endforeach()