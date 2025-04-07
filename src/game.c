#include "rendering.h"
#include "game.h"


int start() {
  printf("Start\n");
  return 0;
}

int update() {
  SDL_FRect transform = { 0, 0, (float)(32 * 2.4), (float)(32 * 2.4) };
  SDL_FRect frame = { 0, 0, 32, 32 };
  if (loadImg("assets/images/player.png", &frame, &transform) == 1) return 1;
  return 0;
}
