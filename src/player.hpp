#pragma once
#include "raylib.h"

class Player {
public:
  int x, y, width, height;
  Texture2D sprite;

  Player();

  void movement(short speed);
};
