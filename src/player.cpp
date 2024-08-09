#include "player.hpp"
#include "raylib.h"

Player::Player() {
  x = (float)GetScreenWidth() / 4;
  y = (float)GetScreenHeight() / 2;

  float size = 3;

  sprite = LoadTexture("assets/player.png");
  sprite.width *= size;
  sprite.height *= size;

  width = sprite.width;
  height = sprite.height;
}

void Player::movement(int speed) {
  if (IsKeyDown(KEY_A)) {
    x -= speed;
    direction = left;
  }
  if (IsKeyDown(KEY_D)) {
    x += speed;
    direction = right;
  }
}

void Player::draw() {
  float sprite_frame = width / 3;
  Rectangle source = {0, 0, sprite_frame, height}; // First frame or idle sprite

  // Animate

  if (direction == left)
    source.width *= -1;

  Vector2 playerCenter = {width / 2, height / 2};
  DrawTexturePro(sprite, source, {x, y, sprite_frame, height}, playerCenter, 0,
                 WHITE);
}
