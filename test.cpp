#include <SDL.h>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_sdl2.h"

#include "src/ui/UIContext.h"
#include "src/renderer/RenderContext.h"


int main(int, char **) {
    RenderContext::create();
    RenderContext::instance()->init();

    UIContext::init(
            RenderContext::instance()->window(),
            RenderContext::instance()->gl_context(),
            GLSL_VERSION
    );

    bool done = false;
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE &&
                event.window.windowID == SDL_GetWindowID(RenderContext::instance()->window()))
                done = true;
        }

        UIContext::instance()->preRender();
        UIContext::instance()->render();

        RenderContext::instance()->preRender(
                (int) ImGui::GetIO().DisplaySize.x,
                (int) ImGui::GetIO().DisplaySize.y
        );

        RenderContext::instance()->render();

        UIContext::instance()->postRender();
        RenderContext::instance()->postRender();
    }

    UIContext::instance()->destroy();
    delete UIContext::instance();

    RenderContext::instance()->destroy();
    delete RenderContext::instance();

    return 0;
}
