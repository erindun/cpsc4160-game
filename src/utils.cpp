#include "utils.h"
#include <SDL_image.h>
#include <iostream>

SDL_Texture *load_texture(SDL_Renderer *renderer, const std::string &filepath) {
  SDL_Surface *surface = IMG_Load(filepath.c_str());
  SDL_Texture *texture = nullptr;
  if (surface == nullptr) {
    std::cout << IMG_GetError() << std::endl;
  } else {
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
      std::cout << SDL_GetError() << std::endl;
    }
  }
  SDL_FreeSurface(surface);
  return texture;
}