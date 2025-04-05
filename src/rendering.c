#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
#include "system.h"

const int WIDTH = 800, HEIGHT = 600;
const int FRAME_DELAY = 16;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *screenSurface = NULL;

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

  screenSurface = SDL_GetWindowSurface(window);
  return 0;
}

int loadImg(str path, float x, float y, float width, float height) {
  SDL_Texture *texture = IMG_LoadTexture(renderer, path);
  if(!texture) {
    return error("Error creating texture: %s\n", SDL_GetError());
  }

  SDL_FRect destRect = { x, y, width, height };
  SDL_RenderTexture(renderer, texture, NULL, NULL);
  SDL_DestroyTexture(texture);
  return 0;
}

void drawFrame() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  // SDL_FRect rect = {WIDTH / 4.0f, HEIGHT / 4.0f, WIDTH / 2.0f, HEIGHT / 2.0f};
  // SDL_RenderFillRect(renderer, &rect);

  loadImg("assets/owl.jpg", 100, 100, 200, 150);

  SDL_RenderPresent(renderer);
  SDL_Delay(FRAME_DELAY);
}
