cmake_minimum_required (VERSION 3.16)

# Set the project name
project(tank-tests)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    tests.cpp
)

add_test(TankTests tank-tests)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC gtest tank
)