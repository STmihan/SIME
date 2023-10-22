//
// Created by stmihan on 10/22/2023.
//

#ifndef SIME_UICONTEXT_H
#define SIME_UICONTEXT_H

#include <SDL.h>

class UIContext {
public:
    inline static UIContext* instance() { return m_instance; }

    static void init(SDL_Window *window, SDL_GLContext gl_context, const char *glsl_version);
    void preRender();
    void render();
    void postRender();
    void destroy();
private:
    UIContext() = default;
    static UIContext* m_instance;
};


#endif //SIME_UICONTEXT_H