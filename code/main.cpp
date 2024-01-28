/*
    Game of Life

    by kelvinhh
    January 27, 2024
*/
#include <iostream>
#include "board.h"
#include "action.h"

int main(int argc, char *argv[]){
    // initialize board
    Board board(10, 10);
    board.randomState();
    board.print();

    return 0;
}