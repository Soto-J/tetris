#include <array>
#include <iostream>
#include <random>
#include <unordered_map>
#include <utility>

#include "fmt/core.h"
#include "raylib.h"

using std::string, std::array, std::vector, std::pair, std::unordered_map;

constexpr int SCREEN_SIZE{750};
constexpr int CELL_COUNT{25};
constexpr int CELL_SIZE{30};

constexpr int TETROMINO_SIZE{4};
constexpr int SHAPE_LIST_SIZE{5};
constexpr int GAME_VIEW_HEIGHT{0};
constexpr int GAME_VIEW_WIDTH{0};
constexpr int PREVIEW_VIEW_HEIGHT{0};
constexpr int PREVIEW_VIEW_WIDTH{0};

struct Tetromino {
  Color color;
  array<Vector2, TETROMINO_SIZE> coordinates;
};

const std::unordered_map<string, Tetromino> SHAPES2 = {
    {"Orange Ricky", {ORANGE, {Vector2{0, 1}, Vector2{1, 1}, Vector2{2, 1}, Vector2{2, 0}}}},  // L
    {"Blue Ricky", {BLUE, {Vector2{0, 0}, Vector2{0, 1}, Vector2{1, 1}, Vector2{2, 1}}}},      // L
    {"Hero", {SKYBLUE, {Vector2{0, 0}, Vector2{1, 0}, Vector2{2, 0}, Vector2{3, 0}}}},         // |
    {"TeeWee", {PURPLE, {Vector2{0, 1}, Vector2{1, 1}, Vector2{1, 0}, Vector2{2, 1}}}},        // T
    {"Smash Boy", {YELLOW, {Vector2{0, 0}, Vector2{1, 0}, Vector2{0, 1}, Vector2{1, 1}}}},     // Block
    {"Cleveland Z", {RED, {Vector2{0, 0}, Vector2{1, 0}, Vector2{1, 1}, Vector2{2, 1}}}},      // Z
    {"Rhode Island Z", {GREEN, {Vector2{0, 1}, Vector2{1, 1}, Vector2{1, 0}, Vector2{2, 0}}}}  // Z
};

class Tetris {
 public:
  Tetris() {
    this->currentTetromino = this->getRandomTetromino();
    this->previewTetromino = this->getRandomTetromino();
  }

  void draw() {
    DrawRectangle(1 * CELL_SIZE, 1 * CELL_SIZE, 15 * CELL_SIZE, 23 * CELL_SIZE, YELLOW);  // Background
    DrawRectangle(18 * CELL_SIZE, 1 * CELL_SIZE, 6 * CELL_SIZE, 8 * CELL_SIZE, YELLOW);   // Preview

    this->drawPreviewTetromino();
    this->drawTetromino();
  }

  void update() {
    for (Vector2 &tetromino : this->getTetrominoCoordinates()) {
      tetromino.y += 1;
    }
  }

  void rotateTetrominoRight() {
    // TODO
  }

  void shiftTetrominoRight() {
    for (Vector2 &tetromino : this->getTetrominoCoordinates()) {
      tetromino.x += 1;
      tetromino.y += 1;
    }
  }

  void shiftTetrominoLeft() {
    for (Vector2 &tetromino : this->getTetrominoCoordinates()) {
      tetromino.x -= 1;
      tetromino.y -= 1;
    }
  }

 private:
  pair<string, Tetromino> currentTetromino;
  pair<string, Tetromino> previewTetromino;

  pair<string, Tetromino> getRandomTetromino() {
    static std::random_device rd;   // Seed for random number generation
    static std::mt19937 gen(rd());  // Mersenne Twister RNG

    // Select a random index
    std::uniform_int_distribution<> dist(0, static_cast<int>(SHAPES2.size()) - 1);

    // Access random element by iterating to the index
    auto it = SHAPES2.begin();
    std::advance(it, dist(gen));

    return std::make_pair(it->first, it->second);
  }

  // CURRENT Tetromino
  void drawTetromino() {
    for (Vector2 &coord : this->getTetrominoCoordinates()) {
      int x = int((coord.x + 1) * CELL_SIZE);
      int y = int((coord.y + 1) * CELL_SIZE);

      DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, this->getTetrominoColor());
    }
  }

  string &getTetrominoName() {
    return this->currentTetromino.first;
  }

  pair<string, Tetromino> &getTetromino() {
    return this->currentTetromino;
  }

  array<Vector2, TETROMINO_SIZE> &getTetrominoCoordinates() {
    return this->currentTetromino.second.coordinates;
  }

  Color &getTetrominoColor() {
    return this->currentTetromino.second.color;
  }

  // PREVIEW Tetromino
  void drawPreviewTetromino() {
    for (Vector2 &coord : this->getPreviewTetrominoCoordinates()) {
      int x = int((coord.x + 19) * CELL_SIZE);
      int y = int((coord.y + 4) * CELL_SIZE);

      DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, this->getPreviewTetrominoColor());
    }
  }

  string &getPreviewTetrominoName() {
    return this->previewTetromino.first;
  }

  pair<string, Tetromino> &getPreviewTetromino() {
    return this->previewTetromino;
  }

  array<Vector2, TETROMINO_SIZE> &getPreviewTetrominoCoordinates() {
    return this->previewTetromino.second.coordinates;
  }

  Color &getPreviewTetrominoColor() {
    return this->previewTetromino.second.color;
  }
};

class Game {
 public:
  Tetris tetris;
  bool gameOver{false};

  void draw() {
    this->tetris.draw();
  }

  void update() {
    this->tetris.update();
  }

  void userInput() {
    if (IsKeyPressed(KEY_RIGHT)) {
      this->tetris.shiftTetrominoRight();
    }

    if (IsKeyPressed(KEY_LEFT)) {
      this->tetris.shiftTetrominoRight();
    }
  }
};

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
