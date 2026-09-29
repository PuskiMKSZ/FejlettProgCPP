#include "Point.h"
#include <cmath>

Point::Point(int x, int y) {
    if (x < 0) {
        this->x = 0;
    } else if (x > M) {
        this->x = M;
    } else {
        this->x = x;
    }

    if (y < 0) {
        this->y = 0;
    } else if (y > M) {
        this->y = M;
    } else {
        this->y = y;
    }
}


int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point& point) const {
    int dx = x - point.x;
    int dy = y - point.y;
    return std::sqrt(dx * dx + dy * dy);
}