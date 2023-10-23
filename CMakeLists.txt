cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME SIME)
set(EXE_TARGET_NAME ${PROJECT_NAME}_EXE)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

set(SOURCES src/Entry.h

        include/Sime.h
        main.cpp

        src/ui/UIContext.cpp
        src/ui/UIContext.h
        src/renderer/RenderContext.cpp
        src/renderer/RenderContext.h
        src/app/Application.h
        src/app/Application.cpp
)

add_executable(${EXE_TARGET_NAME} ${SOURCES})
include_directories(${EXE_TARGET_NAME} src)
include_directories(${EXE_TARGET_NAME} include)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
include_directories(${PROJECT_NAME} include)

# SDL2
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2/x86_64-w64-mingw32/lib/cmake/SDL2")
else ()
    set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2/i686-w64-mingw32/lib/cmake/SDL2")
endif ()

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${EXE_TARGET_NAME} ${SDL2_LIBRARIES})

add_subdirectory(libs/imgui)
target_link_libraries(${PROJECT_NAME} imgui)
target_link_libraries(${EXE_TARGET_NAME} imgui)

add_subdirectory(libs/glad)
target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${EXE_TARGET_NAME} glad)

target_include_directories(${PROJECT_NAME} PUBLIC include)
