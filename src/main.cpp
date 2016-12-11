#include "SDL.h"
#include "handle_events.hpp"

bool    quitting(const SDL_Event &e, SDL_Rect &rect)
{
    (void)rect; (void)e;
    return(false);
}

bool    move_left(SDL_Rect &rect)
{
    rect.x--;
    return (true);
}

bool    move_right(SDL_Rect &rect)
{
    rect.x++;
    return (true);
}

bool    move_up(SDL_Rect &rect)
{
    rect.y--;
    return (true);
}

bool    move_down(SDL_Rect &rect)
{
    rect.y++;
    return (true);
}

int main(int argc, char *argv[]) {
    (void)argc; (void) argv;
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    int posX = 100, posY = 100, width = 320, height = 240;

    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("Hello Back-Bone", posX, posY, width, height, 0);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect red_rectangle;
    red_rectangle.x = 40;
    red_rectangle.y = 40;
    red_rectangle.w = 40;
    red_rectangle.h = 40;

    handle_events< SDL_Rect & >   events;
    events.add_event(SDL_QUIT, quitting);
    events.add_key_event(SDL_KEYDOWN, SDLK_LEFT, move_left);
    events.add_key_event(SDL_KEYDOWN, SDLK_RIGHT, move_right);
    events.add_key_event(SDL_KEYDOWN, SDLK_UP, move_up);
    events.add_key_event(SDL_KEYDOWN, SDLK_DOWN, move_down);

    while (events.check(red_rectangle))
    {
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
