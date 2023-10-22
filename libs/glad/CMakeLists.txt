cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME glad)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} STATIC
        src/glad.c
        include/glad/glad.h
        include/KHR/khrplatform.h
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
