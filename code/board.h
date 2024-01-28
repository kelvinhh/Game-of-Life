#include <iostream>
#include <random>
#include "cell.h"
#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
    int width;
    int height;
    Cell **board;
public:
    Board(int width, int height);
    ~Board();
    void print();

    // randomize the state of the board
    void randomState();
};

#endif