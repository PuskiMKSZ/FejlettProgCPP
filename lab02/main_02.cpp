#include <iostream>
#include "../lab02/Point.h"
#include "../lab02/util.h"
using namespace std;
int main(int argc, char** argv) {
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(10, 10);
    Point * pp2 = new Point(10, 50);
    Point * pp3 = new Point(50, 50);
    Point * pp4 = new Point(50, 10);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    pp1->print();

    double distance1 = distanceF(*pp1,*pp2);
    cout<<"distance a b : " <<distance1<<endl;
    cout<<"is square a b c d : " <<isSquare(*pp1,*pp2,*pp3,*pp4)<<endl;
    delete pp1;
    delete pp2;
    return 0;
}