#pragma once

#include <string>
#include <SDL.h>

SDL_Texture *load_texture(SDL_Renderer *renderer, const std::string &filepath);