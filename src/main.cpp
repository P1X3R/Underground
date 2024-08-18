#include "player.hpp"
#include "raylib.h"

int main() {
  // Initialize
  InitWindow(800, 450, "Underground");
  SetTargetFPS(60);

  Player player;
  Rectangle ground = {0.f, (float)GetScreenHeight(), (float)GetScreenWidth(),
                      1.f};

  // Game loop
  while (!WindowShouldClose()) {
    // Event handling
    player.movement(4);

    if (CheckCollisionRecs({player.x, player.y, player.width, player.height},
                           ground)) {
      player.canMove.down = false;
    } else
      player.canMove.down = true;

    // Drawing
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawRectangleLines(player.x, player.y, player.width / 3, player.height,
                       BLACK);
    player.draw();

    EndDrawing();
  }

  // Uninitialize
  UnloadTexture(player.sprite);
  CloseWindow();

  return 0;
}
