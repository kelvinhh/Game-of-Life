#include <iostream>
#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
    int width;
    int height;
    int **board;
public:
    Board(int width, int height);
    ~Board();
    void init();
    void print();
};

#endif