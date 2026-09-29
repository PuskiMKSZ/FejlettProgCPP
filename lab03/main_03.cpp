#include <iomanip>
#include <iostream>
#include "Point.h"
#include "PointSet.h"
#include <set>
using namespace std;

int main(int argc, char** argv) {
    Point p1(2, 3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;

    Point p2(100, 200);
    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;

    Point* pp1 = new Point(10, 10);
    Point* pp2 = new Point(10, 50);

    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;


    cout << "distance " << pp1->distanceTo(*pp2) << endl;
    int t=10;
    PointSet ps(t);


    cout << "--- Generalt pontok ---" << endl;
    ps.printPoints();
    cout << endl;
    cout << "--- Generalt pontok tavolsaga rendezve ---" << endl;
    ps.sortDistances();
    ps.printDistances();
    cout << "--- egyedi tavolsagok szama:" << ps.numDistinctDistances()<< endl;
    cout << endl;

    delete pp1;
    delete pp2;

    int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"
    <<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }



}