#pragma once
#include "rendering.c"

SDL_Window *window;
SDL_Renderer *renderer;

int init();
int drawFrame();
int loadImg(str path, SDL_FRect *frame, SDL_FRect *transform);
int loadAnim(str path, SDL_FRect *frames, i8 frameCount, SDL_FRect *transform);
