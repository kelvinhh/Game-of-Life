#include "cell.h"

Cell::Cell(): x{0}, y{0}, alive{false} {}
bool Cell::isAlive() {
    return this->alive;
}
void Cell::goDie() {
    this->alive = false;
}
void Cell::goAlive() {
    this->alive = true;
}
void Cell::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}
char Cell::status() {
    if (this->alive)
        return '#';
    else
        return ' ';
}