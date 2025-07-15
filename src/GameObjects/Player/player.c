#include "player.h"
#include "../Core/rendering.h"
#include "../../Animations/Player/playerAnimations.c"


int drawPlayer() {
  SDL_FRect transform = { 0, 0, (float)(32 * 2.4), (float)(32 * 2.4) };
  i8 frameCount = 4;
  if (loadAnim("assets/sprites/player.png", idleAnim, frameCount, &transform) == 1) return error("Failed to load player");
  return 0;
}
