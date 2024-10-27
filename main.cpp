#include <fmt/core.h>
#include <raylib.h>

#include <iostream>

int main(int, char**) {
  //   fmt::print("Hello World!");
  InitWindow(750, 750, "Retro Tetris");

  while (!WindowShouldClose()) {
    BeginDrawing();

    DrawText("Tetris Game!!!!", 190, 200, 20, LIGHTGRAY);
    ClearBackground(RED);

    EndDrawing();
  }

  CloseWindow();
}
