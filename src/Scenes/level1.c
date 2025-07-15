#include "../Core/rendering.h"
#include "level1.h"


int drawBackground() {
  int width, height;
  SDL_GetWindowSizeInPixels(window, &width, &height);
  SDL_FRect bgTransform = { 0, 0, (float)width, (float)height };
  if (loadImg("assets/sprites/background.png", NULL, &bgTransform) == 1) return error("Failed to load background");
  return 0;
}

int start() {
  return 0;
}

int update() {
  drawBackground();
  
  SDL_FRect transform = { 0, 0, (float)(32 * 2.4), (float)(32 * 2.4) };
  SDL_FRect frame = { 0, 0, 32, 32 };
  if (loadImg("assets/sprites/player.png", &frame, &transform) == 1) return error("Failed to load player");
  return 0;
}
