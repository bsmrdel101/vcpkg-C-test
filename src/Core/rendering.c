#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
#include "system.h"
#include "../Scenes/level1.h"


const u16 WIDTH = 800, HEIGHT = 600;
const u8 FRAME_DELAY = 16;
const u8 BG_COLOR[] = {0, 0, 0, 255};
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int init() {
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    return error("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }

  window = SDL_CreateWindow("Game", WIDTH, HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_RESIZABLE);
  if (window == NULL) {
    return error("Could not create window: %s\n", SDL_GetError());
  }

  renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    return error("Renderer Creation Error: %s\n", SDL_GetError());
  }

  if (start() == 1) return 1;
  return 0;
}

int loadImg(str path, SDL_FRect *frame, SDL_FRect *transform) {
  SDL_Texture *texture = IMG_LoadTexture(renderer, path);
  if(!texture) {
    return error("Error creating texture: %s\n", SDL_GetError());
    return 1;
  }

  SDL_RenderTexture(renderer, texture, frame, transform);
  SDL_DestroyTexture(texture);
  return 0;
}

int loadAnim(str path, SDL_FRect *frames, i8 frameCount, SDL_FRect *transform) {
  SDL_Texture *texture = IMG_LoadTexture(renderer, path);
  if(!texture) {
    return error("Error creating texture: %s\n", SDL_GetError());
    return 1;
  }

  int i;
  for (i = 0; i < frameCount; i++) {
    SDL_RenderTexture(renderer, texture, &frames[i], transform);
  }
  SDL_DestroyTexture(texture);
  return 0;
}

int drawFrame() {
  SDL_SetRenderDrawColor(renderer, BG_COLOR[0], BG_COLOR[1], BG_COLOR[2], BG_COLOR[3]);
  SDL_RenderClear(renderer);

  if (update() == 1) return 1;

  SDL_RenderPresent(renderer);
  SDL_Delay(FRAME_DELAY);
  return 0;
}
