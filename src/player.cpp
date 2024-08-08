#include "player.hpp"
#include "raylib.h"

Player::Player() {
  x = GetScreenWidth() / 4;
  y = GetScreenHeight() / 2;

  sprite = LoadTexture("img/player.png");

  width = 10;
  height = 10;
}

void Player::movement(short speed) {
  if (IsKeyDown(KEY_A))
    x -= speed;
  if (IsKeyDown(KEY_D))
    x += speed;
}
