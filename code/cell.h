#ifndef _CELL_H_
#define _CELL_H_

class Cell{
    int x;
    int y;
    int neighbors;
    bool alive;
public:
    Cell();
    bool isAlive();
    void goDie();
    void goAlive();
    void setPos(int x, int y);
    void setNeighbors(int _neighbors);
    char getStatus();
    int getNeighbors();
    void update();
};

#endif