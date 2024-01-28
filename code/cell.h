#ifndef _CELL_H_
#define _CELL_H_

class Cell{
    int x;
    int y;
    bool alive;
public:
    Cell();
    bool isAlive();
    void goDie();
    void goAlive();
    void setPos(int x, int y);
};

#endif