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
    DrawRectangleLines(player.x, player.y, player.width, player.height, BLACK);

    EndDrawing();
  }

  // Uninitialize
  CloseWindow();

  return 0;
}
