#include <iostream>
#include <random>
#include <fstream>
#include "cell.h"
#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
    int width;
    int height;
    Cell **board;
    int direction[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    // update the state for each cell
    void update();
public:
    Board(int width, int height);
    ~Board();
    void print();
    void read_file(std::ifstream& file);

    // randomize the state of the board
    void randomState();
    // go to next generation
    void next();
};

#endif