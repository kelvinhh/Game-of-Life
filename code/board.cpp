#include "board.h"

Board::Board(int width, int height) {
    this->width = width;
    this->height = height;
}
Board::~Board() {
    for (int i = 0; i < height; i++) {
        delete board[i];
        board[i] = nullptr;
    }
    delete[] board;
}
void Board::init() {
    // allocate memory for board
    board = new int*[height];
    for (int i = 0; i < height; i++) {
        board[i] = new int[width];
    }
    // set default value to 1
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = 1;
        }
    }
}
void Board::print() {
    for (int i = 0; i < height; i++) {
        std::cout << "|";
        for (int j = 0; j < width; j++) {
            std::cout << board[i][j] << "|";
        }
        std::cout << std::endl;
    }
}