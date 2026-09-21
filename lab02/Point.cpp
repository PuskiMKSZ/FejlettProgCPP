#include "../lab02/Point.h"

#include <iostream>
#include <math.h>
#include <ostream>
//#include <bits/valarray_after.h>
using namespace std;
Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    }
    else {
        this->x = 0; this->y = 0;
    }
}
int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
   cout<<" X: "<<getX()<<" Y:"<<getY()<<endl;
}

