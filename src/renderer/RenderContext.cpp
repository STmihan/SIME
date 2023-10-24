//
// Created by stmihan on 10/22/2023.
//
#include <iostream>

#include "RenderContext.h"

RenderContext *RenderContext::m_instance = nullptr;

int RenderContext::init(int width, int height, const char *title) {
    m_width = width;
    m_height = height;
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return -1;
    }


    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);


    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);

    m_window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_gl_context = SDL_GL_CreateContext(m_window);
    SDL_GL_MakeCurrent(m_window, m_gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync
    if (!gladLoadGL()) {
        std::cerr << "[ERROR] Couldn't initialize glad" << std::endl;
        return -1;
    } else {
        std::cout << "[INFO] glad initialized" << std::endl;
    }

    return 0;
}

void RenderContext::preRender(int width, int height) {
    SDL_Rect vp{0, 0, width, height};
    SDL_RenderSetViewport(m_renderer, &vp);
}

void RenderContext::render() {
}

void RenderContext::postRender() {
    SDL_GL_SwapWindow(m_window);
}

void RenderContext::destroy() {
    SDL_GL_DeleteContext(m_gl_context);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
