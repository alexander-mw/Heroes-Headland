cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(heroes-headland)
add_executable(${PROJECT_NAME} ./src/glad.c ./src/main.c)
target_link_libraries(${PROJECT_NAME} GL dl glfw)
