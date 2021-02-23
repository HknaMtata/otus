# Set the project name
project(matrix)

# Add a library with the above sources
add_library(
    ${PROJECT_NAME} matrix.cpp matrix_utils.cpp matrix_operations.cpp
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}
)