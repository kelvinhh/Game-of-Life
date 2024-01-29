#include "board.h"

Board::Board(int _width, int _height): width{_width}, height{_height} {
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
    for (int i = 0; i < width + 2; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (int i = 0; i < height; i++) {
        std::cout << "|";
        for (int j = 0; j < width; j++) {
            std::cout << board[i][j].getStatus();
        }
        std::cout << "|" << std::endl;
    }
    for (int i = 0; i < width + 2; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}
void Board::read_file(std::ifstream& file) {
    std::string line;
    int i = 0;
    while (getline(file, line)) {
        for (int j = 0; j < line.length(); j++) {
            if (line[j] == '1') {
                board[i][j].goAlive();
            } else {
                board[i][j].goDie();
            }
        }
        i++;
    }
    update();
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
    update();
}
void Board::update() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int neighbour = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + direction[k][0];
                int y = j + direction[k][1];
                if (x >= 0 && x < height && y >= 0 && y < width) {
                    if (board[x][y].isAlive()) {
                        neighbour++;
                    }
                }
            }
            board[i][j].setNeighbors(neighbour);
        }
    }
}
void Board::next() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            board[i][j].update();
        }
    }
    update();
}