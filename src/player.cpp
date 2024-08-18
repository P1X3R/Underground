#include "player.hpp"

#include "raylib.h"

#define GRAVITY .2f

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
  bool keyRight = IsKeyDown(KEY_D);
  bool keyLeft = IsKeyDown(KEY_A);
  bool keySpace = IsKeyPressed(KEY_SPACE);

  if (keyLeft and canMove.left) {
    x -= speed;
    animation = walking;
    direction = left;
  }
  if (keyRight and canMove.right) {
    x += speed;
    animation = walking;
    direction = right;
  }
  if (keySpace and not canMove.down) {
    canMove.down = true;
    velocity.y -= 6.f;
    animation = jumping;
  }
  if (not keyLeft and not keyRight or keyLeft and keyRight) animation = idle;

  // Make he fall
  if (canMove.down)
    velocity.y += GRAVITY;
  else
    velocity.y = 0.f;

  y += velocity.y;
}

void Player::draw() {
  float spriteFrame = width / 3.f;
  Rectangle frames[3] = {{0, 0, spriteFrame, height},  // Idle animation
                         {spriteFrame, 0, spriteFrame,
                          height},  // First frame of walking animation
                         {spriteFrame * 2, 0, spriteFrame,
                          height}};  // Second frame of walking animation

  if (direction == left)
    for (int i = 0; i < 3; i++) frames[i].width *= -1;

  // Change of frame
  if (animation == walking and not canMove.down) {
    frameTimer += GetFrameTime();
    if (frameTimer >= frameRate) {
      frameTimer = .0;
      currentFrame++;
      if (currentFrame >= 3) currentFrame = 1;
    }
  } else if (animation == jumping)
    currentFrame = 2;
  else if (animation == idle)
    currentFrame = 0;

  DrawTexturePro(sprite, frames[currentFrame], {x, y, spriteFrame, height},
                 {0.f, 0.f}, 0, WHITE);
}
