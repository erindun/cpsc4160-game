#include "ui_handler.h"
#include <SDL.h>
#include "constants.h"
#include <SDL_ttf.h>
#include <iostream>

UIHandler::UIHandler(SDL_Renderer *renderer) : renderer{renderer} {}

void UIHandler::render() { 
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
	SDL_Rect bg = {0, 0, SCENE_WIDTH, SCENE_HEIGHT};
	SDL_RenderFillRect(renderer, &bg);
    auto font = TTF_OpenFont("../assets/munro.ttf", 36);
    if (!font) {
        std::cout << SDL_GetError() << std::endl;
    }

    auto text_surface = TTF_RenderText_Solid(font, "PAUSED", SDL_Color{255, 255, 255});
    if (!text_surface) {
      std::cout << SDL_GetError() << std::endl;
    }
    auto graphic = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_Rect rect = {0, 0, 200, 200};
    SDL_RenderCopy(renderer, graphic, nullptr, &rect);
}