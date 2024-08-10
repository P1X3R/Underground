#include "player.hpp"

#include "raylib.h"

Player::Player() {
  float size = 4;

  x = (float)GetScreenWidth() / 4;
  y = (float)GetScreenHeight() / 2;

  sprite = LoadTexture("assets/player.png");
  sprite.width *= size;
  sprite.height *= size;

  width = sprite.width;
  height = sprite.height;
}

void Player::movement(int speed) {
  if (IsKeyDown(KEY_A)) {
    x -= speed;
    animation = walking;
    direction = left;
  }
  if (IsKeyDown(KEY_D)) {
    x += speed;
    animation = walking;
    direction = right;
  }
  if ((not IsKeyDown(KEY_A) and not IsKeyDown(KEY_D)) or
      ((IsKeyDown(KEY_A) and IsKeyDown(KEY_D))))
    animation = idle;
}

void Player::draw() {
  float spriteFrame = width / 3.f;
  Rectangle frames[3] = {{0, 0, spriteFrame, height},  // Idle animation
                         {spriteFrame, 0, spriteFrame,
                          height},  // First frame of walking animation
                         {spriteFrame * 2, 0, spriteFrame,
                          height}};  // Second frame of walking animation
  Vector2 playerCenter = {width / 2, height / 2};

  if (direction == left)
    for (int i = 0; i < 3; i++) frames[i].width *= -1;

  // Change of frame
  if (animation != idle) {
    frameTimer += GetFrameTime();
    if (frameTimer >= frameRate) {
      frameTimer = .0;
      currentFrame++;
      if (currentFrame >= 3) currentFrame = 1;
    }
  } else
    currentFrame = 0;

  DrawTexturePro(sprite, frames[currentFrame], {x, y, spriteFrame, height},
                 playerCenter, 0, WHITE);
}
