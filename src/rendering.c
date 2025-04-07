#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
#include "system.h"


const int WIDTH = 800, HEIGHT = 600;
const int FRAME_DELAY = 16;
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

int drawFrame() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  // SDL_FRect rect = {WIDTH / 4.0f, HEIGHT / 4.0f, WIDTH / 2.0f, HEIGHT / 2.0f};
  // SDL_RenderFillRect(renderer, &rect);

  SDL_FRect transform = { 0, 0, (float)(32 * 2.4), (float)(32 * 2.4) };
  SDL_FRect frame = { 0, 0, 32, 32 };
  if (loadImg("assets/images/player.png", &frame, &transform) == 1) return 1;

  SDL_RenderPresent(renderer);
  SDL_Delay(FRAME_DELAY);
  return 0;
}
