#ifndef TETRIS_H
#define TETRIS_H

#include <array>
#include <iostream>
#include <random>
#include <unordered_map>
#include <utility>

#include "fmt/core.h"
#include "raylib.h"

using std::string, std::array, std::vector, std::pair, std::unordered_map;

constexpr int SCREEN_SIZE{750};
constexpr int CELL_SIZE{30};

constexpr int CELL_COUNT{25};

constexpr int TETROMINO_SIZE{4};
constexpr int SHAPE_LIST_SIZE{5};

// Game Viewport
constexpr int GAME_VIEW_X{1};
constexpr int GAME_VIEW_Y{1};
constexpr int GAME_VIEW_WIDTH{15};
constexpr int GAME_VIEW_HEIGHT{23};

// Preview Viewport
constexpr int PREVIEW_VIEW_X{18};
constexpr int PREVIEW_VIEW_Y{1};
constexpr int PREVIEW_VIEW_HEIGHT{6};
constexpr int PREVIEW_VIEW_WIDTH{8};

struct Tetromino {
  Color color;
  array<Vector2, TETROMINO_SIZE> coordinates;
};

const std::unordered_map<string, Tetromino> SHAPES2 = {
    {"Orange Ricky", {ORANGE, {Vector2{1, 1}, Vector2{2, 1}, Vector2{3, 1}, Vector2{3, 0}}}},  // L
    {"Blue Ricky", {BLUE, {Vector2{1, 0}, Vector2{1, 1}, Vector2{2, 1}, Vector2{3, 1}}}},      // L
    {"Hero", {SKYBLUE, {Vector2{1, 0}, Vector2{2, 0}, Vector2{3, 0}, Vector2{4, 0}}}},         // |
    {"TeeWee", {PURPLE, {Vector2{1, 1}, Vector2{2, 1}, Vector2{2, 0}, Vector2{3, 1}}}},        // T
    {"Smash Boy", {YELLOW, {Vector2{1, 0}, Vector2{2, 0}, Vector2{1, 1}, Vector2{2, 1}}}},     // Block
    {"Cleveland Z", {RED, {Vector2{1, 0}, Vector2{2, 0}, Vector2{2, 1}, Vector2{3, 1}}}},      // Z
    {"Rhode Island Z", {GREEN, {Vector2{1, 1}, Vector2{2, 1}, Vector2{2, 0}, Vector2{3, 0}}}}  // Z
};

class Tetris {
 public:
  Tetris();

  void draw();

  bool isEligible();

  void update();

  void rotateTetrominoRight();

  void shiftTetrominoRight();

  void shiftTetrominoLeft();

  void shiftTetrominoDown();

 private:
  pair<string, Tetromino> currentTetromino;
  pair<string, Tetromino> previewTetromino;

  pair<string, Tetromino> getRandomTetromino();

  // CURRENT Tetromino
  void drawTetromino();

  bool isInbound();

  string &getTetrominoName();

  pair<string, Tetromino> &getTetromino();

  array<Vector2, TETROMINO_SIZE> &getTetrominoCoordinates();

  Color &getTetrominoColor();

  // PREVIEW Tetromino
  void drawPreviewTetromino();

  string &getPreviewTetrominoName();

  pair<string, Tetromino> &getPreviewTetromino();

  array<Vector2, TETROMINO_SIZE> &getPreviewTetrominoCoordinates();

  Color &getPreviewTetrominoColor();
};

#endif  // TETRIS_H
