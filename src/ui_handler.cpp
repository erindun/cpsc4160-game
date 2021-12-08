#include "ui_handler.h"
#include <SDL.h>
#include "constants.h"

UIHandler::UIHandler(SDL_Renderer *renderer) : renderer{renderer} {}

void UIHandler::render() { 
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
	SDL_Rect bg = {0, 0, SCENE_WIDTH, SCENE_HEIGHT};
	SDL_RenderFillRect(renderer, &bg);
}