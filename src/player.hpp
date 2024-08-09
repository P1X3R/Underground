#pragma once
#include "raylib.h"

enum playerAnimation { idle, walking };
enum playerDirection { left, right };

class Player {
 public:
  float x, y, width, height;
  Texture2D sprite;

  Player();

  void movement(int speed);
  void draw();

 protected:
  playerDirection direction;
  playerAnimation animation;
  int currentFrame = 1;
  float frameRate = .1f;
  float frameTimer = .0f;
};
