#include <stdio.h>
#include <stdlib.h>


int error(char *msg, ...) {
  SDL_Log(msg);
  return 1;
}
