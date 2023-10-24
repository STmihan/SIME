cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME SIME)
set(EXE_TARGET_NAME ${PROJECT_NAME}_EXE)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

if (MINGW)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
endif ()

set(SOURCES
        include/Sime.h

        src/Entry.h
        src/types.h
        src/ui/UIContext.cpp
        src/ui/UIContext.h
        src/renderer/RenderContext.cpp
        src/renderer/RenderContext.h
        src/app/Application.h
        src/app/Application.cpp
)

add_executable(${EXE_TARGET_NAME} main.cpp ${SOURCES})
include_directories(${EXE_TARGET_NAME} src)
include_directories(${EXE_TARGET_NAME} include)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src)

# SDL2
if (MSVC)
    set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2-VC/cmake")
endif (MSVC)
if (MINGW)
    set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2-MinGW/cmake")
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

add_subdirectory(libs/glm)
target_link_libraries(${PROJECT_NAME} glm)
target_link_libraries(${EXE_TARGET_NAME} glm)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
