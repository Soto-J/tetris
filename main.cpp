#include <iostream>
#include "fmt/core.h"
#include "raylib.h"
#include "game/Game.h"

double previousTime = 0;

bool eventTriggered(double interval) {
  double currentTime = GetTime();

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    return true;
  }

  return false;
}

int main(int, char **) {
  InitWindow(SCREEN_SIZE, SCREEN_SIZE, "Retro Tetris");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    BeginDrawing();

    if (eventTriggered(0.4)) {
      game.update();
    }

    game.userInput();

    DrawText("Tetris Game!!!!", SCREEN_SIZE / 2, 200, 20, LIGHTGRAY);
    ClearBackground(BLACK);

    game.draw();

    EndDrawing();
  }

  CloseWindow();
}
