//
// Created by stmihan on 10/23/2023.
//

#ifndef SIME_APPLICATION_H
#define SIME_APPLICATION_H

#include "SDL2/SDL.h"
#include "imgui.h"

namespace Sime {

    class Application {
    public:
        Application() = default;
        virtual ~Application() = default;

        void run();
        void close() { m_exit = true; }

    protected:
        virtual void processEvents(const SDL_Event *event) = 0;
        virtual void draw(SDL_Renderer* renderer) = 0;
        virtual void drawUI(ImGuiIO& io) = 0;

    private:
        bool shouldClose() const { return m_exit; }
        bool m_exit = false;
    };
}
#endif //SIME_APPLICATION_H
