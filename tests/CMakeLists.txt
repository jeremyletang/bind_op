# min config
cmake_minimum_required (VERSION 2.8.1)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -W -Wall -Wextra -Wno-unused-function") #enable C++14
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

include_directories (
    ${PROJECT_SOURCE_DIR}/include
)

add_executable (bind_op_tests ${SOURCES})
