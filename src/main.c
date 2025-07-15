#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
#include "./Core/rendering.h"
#include "./Scenes/level1.c"


int main(int argc, str argv[]) {
  if(init() == 1) {
    return error("Error during initialization");
  }

  bool running = true;
  bool error = false;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) running = false;
    }

    if ((!error && drawFrame()) == 1) error = true;
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
