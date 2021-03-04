cmake_minimum_required (VERSION 3.16)

project(otus-homeworks)

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

set(GOOGLE_TEST_DIR submodules/googletest)
set(GOOGLE_TEST_INCLUDES ${GOOGLE_TEST_DIR}/googletest/include ${GOOGLE_TEST_DIR}/googlemock/include )

# Add sub directories
add_subdirectory(${GOOGLE_TEST_DIR})
add_subdirectory(1/2-matrix)

add_compile_options(
    ${PROJECT_NAME} PUBLIC -std=c++17 -Wall -Wextra -Werror -Wpedantic # -Wno-unused-parameter -Wno-missing-field-initializer
)