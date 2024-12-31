cmake_minimum_required(VERSION 3.12)

project(C-Mente VERSION 0.1.0.1 LANGUAGES C)

include_directories("src/core")

file(GLOB SRC_FILES src/*.c src/core/*.c)

add_executable(CMENTE_BINARY ${SRC_FILES})

set_target_properties(CMENTE_BINARY PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set_target_properties(CMENTE_BINARY PROPERTIES OUTPUT_NAME "cmente")

