//
// Created by charl on 10/31/2024.
//

#include "Tetris.h"

Tetris::Tetris() {
    this->currentTetromino = this->getRandomTetromino();
    this->previewTetromino = this->getRandomTetromino();
}


void Tetris::draw() {
    DrawRectangle(1 * CELL_SIZE, 1 * CELL_SIZE, 15 * CELL_SIZE, 23 * CELL_SIZE, YELLOW); // Background
    DrawRectangle(18 * CELL_SIZE, 1 * CELL_SIZE, 6 * CELL_SIZE, 8 * CELL_SIZE, YELLOW); // Preview
    this->drawPreviewTetromino();
    this->drawTetromino();
}


bool Tetris::isEligible() {
    auto vector2s = this->getTetrominoCoordinates();
    for (auto i = vector2s.begin(); i != vector2s.end(); i++) {
        if(i->y+1 > bottom()) {
            return false;
        }
    }
    //How can we calculate where the lowest point a tetris model can go?+
    return true;
}
void Tetris::update() {
    if(this->isEligible()) {
        for (Vector2 &tetromino: this->getTetrominoCoordinates()) {
            if (tetromino.y < this->bottom()) {
                tetromino.y += 1;
            } else {
                break;
            }
        }
    } else {
        //TODO: Choose Next
    }
}

int Tetris::bottom() {
    return (SCREEN_SIZE - (CELL_SIZE * 3)) / CELL_SIZE;
}


void Tetris::rotateTetrominoRight() {
    // TODO
}

void Tetris::shiftTetrominoRight() {
    for (Vector2 &tetromino: this->getTetrominoCoordinates()) {
        tetromino.x += 1;
        //tetromino.y += 1;
    }
}

void Tetris::shiftTetrominoLeft() {
    for (Vector2 &tetromino: this->getTetrominoCoordinates()) {
        tetromino.x -= 1;
        //tetromino.y -= 1;
    }
}

void Tetris::shiftTetrominoDown() {
    for (Vector2 &tetromino: this->getTetrominoCoordinates()) {
        tetromino.y += 1;
    }
}

pair<string, Tetromino> Tetris::getRandomTetromino() {
    static std::random_device rd; // Seed for random number generation
    static std::mt19937 gen(rd()); // Mersenne Twister RNG

    // Select a random index
    std::uniform_int_distribution<> dist(0, static_cast<int>(SHAPES2.size()) - 1);

    // Access random element by iterating to the index
    auto it = SHAPES2.begin();
    std::advance(it, dist(gen));

    return std::make_pair(it->first, it->second);
}

// CURRENT Tetromino
void Tetris::drawTetromino() {
    for (Vector2 &coord: this->getTetrominoCoordinates()) {
        int x = int((coord.x + 1) * CELL_SIZE);
        int y = int((coord.y + 1) * CELL_SIZE);

        DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, this->getTetrominoColor());
    }
}

string &Tetris::getTetrominoName() {
    return this->currentTetromino.first;
}

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
    for (Vector2 &coord: this->getPreviewTetrominoCoordinates()) {
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
