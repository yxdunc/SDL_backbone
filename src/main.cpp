#include "SDL.h"
#include "handle_events.hpp"

int main(int argc, char *argv[]) {
    (void)argc; (void) argv;
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    int posX = 100, posY = 100, width = 320, height = 240;

    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Rect red_rectangle;
    red_rectangle.x = 40;
    red_rectangle.y = 40;
    red_rectangle.w = 40;
    red_rectangle.h = 40;
    handle_events   events;
    while (1) {
        events.check();
        
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1);
        SDL_RenderDrawRect(renderer, &red_rectangle);
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 1);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}