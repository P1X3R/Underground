#include "player.hpp"
#include "raylib.h"

int main() {
  // Initialize
  InitWindow(800, 450, "Underground");
  SetTargetFPS(60);

  Player player;

  // Game loop
  while (!WindowShouldClose()) {
    // Event handling
    player.movement(4);

    // Drawing
    BeginDrawing();

    ClearBackground(RAYWHITE);
    player.draw();

    EndDrawing();
  }

  // Uninitialize
  UnloadTexture(player.sprite);
  CloseWindow();

  return 0;
}
