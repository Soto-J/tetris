#include "Tetris.hpp"

Tetris::Tetris() {
  this->currentTetromino = this->getRandomTetromino();
  this->previewTetromino = this->getRandomTetromino();
}

void Tetris::draw() {
  this->drawTetromino();
  this->drawPreviewTetromino();
}

void Tetris::update() { 
  this->shiftTetrominoDown();
 }

void Tetris::shiftTetrominoDown(int bottomBound) {
  auto &tetrominoCoords = this->getTetrominoCoordinates();

  for (const Vector2 &tetromino : tetrominoCoords) {
    if (tetromino.y + 1 >= bottomBound) {
      std::cout << "Cannot move down" << std::endl;
      return;
    }
  }

  for (Vector2 &tetromino : this->getTetrominoCoordinates()) {
    tetromino.y += 1;
  }
}

void Tetris::rotateTetrominoRight() {
  // TODO
}

void Tetris::shiftTetrominoLeft(int leftBound) {
  auto &tetrominoCoords = this->getTetrominoCoordinates();

  for (const Vector2 &tetromino : tetrominoCoords) {
    if (tetromino.x < leftBound) {
      return;
    }
  }

  for (Vector2 &tetromino : tetrominoCoords) {
    tetromino.x -= 1;
  }
}

void Tetris::shiftTetrominoRight(int rightBound) {
  auto &tetrominoCoords = this->getTetrominoCoordinates();

  for (const Vector2 &tetromino : tetrominoCoords) {
    if (tetromino.x + 1 >= rightBound) {
      std::cout << "Cannot move right" << std::endl;
      return;
    }
  }

  for (Vector2 &tetromino : tetrominoCoords) {
    tetromino.x += 1;
  }
}

bool Tetris::isInbound() {
  for (const Vector2 &tetromino : this->getTetrominoCoordinates()) {
    if (tetromino.x - 1 < GAME_VIEW_X || tetromino.x + 1 >= GAME_VIEW_WIDTH ||
        tetromino.y + 1 >= GAME_VIEW_HEIGHT) {
      return false;
    }
  }

  return true;
}

pair<string, Tetromino> Tetris::getRandomTetromino() {
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
void Tetris::drawTetromino() {
  for (Vector2 &coord : this->getTetrominoCoordinates()) {
    int x = int((coord.x + 1) * CELL_SIZE);
    int y = int((coord.y + 1) * CELL_SIZE);

    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, this->getTetrominoColor());
  }
}

string &Tetris::getTetrominoName() { return this->currentTetromino.first; }

pair<string, Tetromino> &Tetris::getTetromino() {
  return this->currentTetromino;
}

array<Vector2, TETROMINO_SIZE> &Tetris::getTetrominoCoordinates() {
  return this->currentTetromino.second.coordinates;
}

Color &Tetris::getTetrominoColor() {
  return this->currentTetromino.second.color;
}

// PREVIEW Tetromino
void Tetris::drawPreviewTetromino() {
  for (Vector2 &coord : this->getPreviewTetrominoCoordinates()) {
    int x = int((coord.x + 19) * CELL_SIZE);
    int y = int((coord.y + 4) * CELL_SIZE);

    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, this->getPreviewTetrominoColor());
  }
}

string &Tetris::getPreviewTetrominoName() {
  return this->previewTetromino.first;
}

pair<string, Tetromino> &Tetris::getPreviewTetromino() {
  return this->previewTetromino;
}

array<Vector2, TETROMINO_SIZE> &Tetris::getPreviewTetrominoCoordinates() {
  return this->previewTetromino.second.coordinates;
}

Color &Tetris::getPreviewTetrominoColor() {
  return this->previewTetromino.second.color;
}
