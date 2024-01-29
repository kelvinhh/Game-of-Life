#include "cell.h"

Cell::Cell(): x{0}, y{0}, neighbors{0}, alive{false} {}
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
void Cell::setNeighbors(int _neighbors) {
    this->neighbors = _neighbors;
}
char Cell::getStatus() {
    if (this->alive)
        return '#';
    else
        return ' ';
}
int Cell::getNeighbors() {
    return this->neighbors;
}
void Cell::update() {
    if (this->alive) {
        if (this->neighbors == 0 || this->neighbors == 1 || this->neighbors > 3) {
            this->alive = false;
        }
    } else {
        if (this->neighbors == 3) {
            this->alive = true;
        }
    }
}