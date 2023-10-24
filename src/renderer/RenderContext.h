//
// Created by stmihan on 10/22/2023.
//

#ifndef SIME_RENDERCONTEXT_H
#define SIME_RENDERCONTEXT_H

#include "SDL.h"
#include "glad/glad.h"

#define GLSL_VERSION "#version 130"

class RenderContext {
public:

    static RenderContext *instance() { return m_instance; }

    static void create() { m_instance = new RenderContext(); }

    int init(int width, int height, const char *title);

    void preRender(int width, int height);

    void render();

    void postRender();

    void destroy();


    SDL_Window *window() { return m_window; }

    SDL_Renderer *renderer() { return m_renderer; }

    SDL_GLContext gl_context() { return m_gl_context; }

private:
    RenderContext() = default;

    static RenderContext *m_instance;
    int m_width, m_height;

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_GLContext m_gl_context;
};


#endif //SIME_RENDERCONTEXT_H
