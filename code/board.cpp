#include "board.h"

Board::Board(int width, int height): width{width}, height{height} {
    board = new Cell*[height];
    for (int i = 0; i < height; i++) {
        board[i] = new Cell[width];
    }
    // set default value to 1
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j].setPos(i, j);
        }
    }
}
Board::~Board() {
    for (int i = 0; i < height; i++) {
        delete board[i];
        board[i] = nullptr;
    }
    delete[] board;
}
void Board::print() {
    for (int i = 0; i < height; i++) {
        std::cout << "|";
        for (int j = 0; j < width; j++) {
            std::cout << board[i][j].status();
        }
        std::cout << "|" << std::endl;
    }
}
void Board::randomState() {
    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            int n = rand() % 2;
            if (n) {
                board[i][j].goAlive();
            } else {
                board[i][j].goDie();
            }
        }
    }
}