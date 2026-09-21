//
// Created by markt on 2026. 09. 21..
//

#include "util.h"
#include "../lab02/Point.h"
#include <math.h>
double distanceF(const Point& a, const Point& b) {
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    return sqrt(dx*dx + dy*dy);
}
bool isSquare(const Point& a, const Point& b, const Point& c, const Point&
d) {
    double dOF[6];

    dOF[0] = distanceF(a, b);
    dOF[1] = distanceF(a, c);
    dOF[2] = distanceF(a, d);
    dOF[3] = distanceF(b, c);
    dOF[4] = distanceF(b, d);
    dOF[5] = distanceF(c, d);
    qsort(dOF, 6, sizeof(double),compare);
    if (dOF[0] == dOF[1] == dOF[2] == dOF[3] && dOF[4] == dOF[5]) return true;
    return false;

}
void testIsSquare(const char * filename) {

}