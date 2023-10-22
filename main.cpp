#include "SDL.h"

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_TIMER);

    SDL_Window *window = SDL_CreateWindow(
            "SIME",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_OPENGL
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool exit = false;
    while (!exit) {
        SDL_SetRenderDrawColor(renderer, 1, 1, 255, 1);
        SDL_RenderClear(renderer);
        SDL_Rect rect = {0, 0, 100, 100};
        SDL_SetRenderDrawColor(renderer, 255, 1, 1, 1);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                exit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
