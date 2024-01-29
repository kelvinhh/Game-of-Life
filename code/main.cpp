/*
    Game of Life

    by kelvinhh
    January 27, 2024
*/
#include <iostream>
#include <fstream>
#include "board.h"


int main(int argc, char *argv[]){
    // initialize board
    Board board(50, 50);
    // board.randomState();
    std::ifstream f("test.txt");
    board.read_file(f);
    
    while (1) {
        board.print();
        board.next();
        std::cout << "Press enter to continue...";
        std::cin.get();
    }

    return 0;
}