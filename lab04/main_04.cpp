#include <iostream>

#include " Polynomial.h"
#include <cmath>
int main() {

    double c1[] = {2.0, -3.0, 5.0};
    Polynomial p1(2, c1);

    double c2[] = {1.0, 4.0};
    Polynomial p2(1, c2);



    cout << "p1= " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    Polynomial p3 = p1 + p2;
    cout << "p3 = p1 + p2 =" << p3 << endl;

    cout << "derivalt p1 "<< p1.derivative() << endl;

    cout << "p1 horner sema erteke " << p1.evaluate(2) << endl;
}
