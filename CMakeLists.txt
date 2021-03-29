cmake_minimum_required (VERSION 3.16)

project(otus-homeworks)

enable_testing()

set(GOOGLE_TEST_DIR submodules/googletest)
set(GOOGLE_TEST_INCLUDES ${GOOGLE_TEST_DIR}/googletest/include ${GOOGLE_TEST_DIR}/googlemock/include )

add_compile_options(
    -std=c++17 -Wall -Wextra -Werror -Wpedantic
)

# Add sub directories
add_subdirectory(${GOOGLE_TEST_DIR})
add_subdirectory(1/1-tank)
add_subdirectory(1/2-matrix)