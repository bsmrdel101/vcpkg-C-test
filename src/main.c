#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
#include "system.h"
#include "rendering.h"


int main(int argc, str argv[]) {
  if(init() == 1) {
    return error("Error during initialization");
  }

  int running = 1;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) running = 0;
    }

    drawFrame();
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}