cmake_minimum_required (VERSION 3.16)

project(matrix-tests)

# Create the executable
add_executable(
    ${PROJECT_NAME}
    main.cpp
    test.cpp
)

add_test(MatrixTests matrix-tests)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE matrix gtest
)