//
// Created by stmihan on 10/23/2023.
//

#include <iostream>
#include "Application.h"
#include "renderer/RenderContext.h"
#include "ui/UIContext.h"
#include "imgui_impl_sdl2.h"


namespace Sime {
    void Application::run() {
        RenderContext::create();
        RenderContext::instance()->init();

        UIContext::create();
        UIContext::instance()->init(
                RenderContext::instance()->window(),
                RenderContext::instance()->gl_context(),
                GLSL_VERSION
        );


        while (!shouldClose()) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                ImGui_ImplSDL2_ProcessEvent(&event);
                processEvents(&event);
                if (event.type == SDL_QUIT) {
                    close();
                }
                if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE &&
                    event.window.windowID == SDL_GetWindowID(RenderContext::instance()->window())) {
                    close();
                }
            }

            UIContext::instance()->preRender();
            drawUI(ImGui::GetIO());
            UIContext::instance()->render();

            RenderContext::instance()->preRender(
                    (int) ImGui::GetIO().DisplaySize.x,
                    (int) ImGui::GetIO().DisplaySize.y
            );

            draw(RenderContext::instance()->renderer());
            RenderContext::instance()->render();

            UIContext::instance()->postRender();
            RenderContext::instance()->postRender();
        }

        UIContext::instance()->destroy();
        delete UIContext::instance();

        RenderContext::instance()->destroy();
        delete RenderContext::instance();
    }
}
