cmake_minimum_required (VERSION 3.16)

project(1-2-matrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -pthread -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter -Wno-missing-field-initializer")

# Add sub directories
add_subdirectory(src src/build)

# Create the executable
add_executable(${PROJECT_NAME} tests/test.cpp)

target_link_libraries(
    ${PROJECT_NAME} matrix
)