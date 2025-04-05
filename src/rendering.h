#pragma once
#include "rendering.c"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *screenSurface;

int init();
void drawFrame();
