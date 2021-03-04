cmake_minimum_required (VERSION 3.16)

project(1-2-matrix)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter -Wno-missing-field-initializer")

# Add sub directories
add_subdirectory(src)

# Create the executable
add_executable(
    ${PROJECT_NAME} tests/main.cpp tests/test.cpp
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE src
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE ${GOOGLE_TEST_INCLUDES}
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE matrix gtest
)

target_compile_options(
    ${PROJECT_NAME} PRIVATE -pthread # -std=c++17 -Wall -Wextra -Werror -Wpedantic # -Wno-unused-parameter -Wno-missing-field-initializer
)