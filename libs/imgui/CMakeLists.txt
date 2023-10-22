cmake_minimum_required(VERSION 3.26)
set(PROJECT_NAME imgui)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} STATIC
        imgui/imgui.h
        imgui/imgui.cpp
        imgui/imconfig.h
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_internal.h
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h

        # ImGui backends
        imgui/backends/imgui_impl_sdlrenderer2.h
        imgui/backends/imgui_impl_sdlrenderer2.cpp
        imgui/backends/imgui_impl_sdl2.h
        imgui/backends/imgui_impl_sdl2.cpp
        imgui/backends/imgui_impl_opengl3.h
        imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC imgui imgui/backends)

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
