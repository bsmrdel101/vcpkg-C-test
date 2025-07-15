#include "../Core/rendering.h"
#include "../GameObjects/Player/player.c"
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
  drawPlayer();
  return 0;
}
