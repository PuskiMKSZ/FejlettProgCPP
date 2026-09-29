#include "PointSet.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <set>
#include <vector>
#include <filesystem>

using namespace std;

PointSet::PointSet(int n) {
    this->n = n;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, M);

    while (points.size() < n) {
        int x = dis(gen);
        int y = dis(gen);
        bool talalt = false;
        Point a(x, y);
        for (auto &p : points) {
            if (p.getX() == x && p.getY() == y) {
                talalt = true;
                break;
            }

        }
        if (!talalt) {
            points.push_back(Point(x, y));
        }





    }
    this->computeDistances();
}

void PointSet::computeDistances() {
    distances.clear();

    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {

            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}
void PointSet::printPoints() const {
    for (int i = 0; i < points.size(); ++i) {
        cout << points[i].getX() << " " << points[i].getY() << endl;
    }



}
double PointSet::maxDistance() const {
    if (distances.empty()) return 0.0;
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    if (distances.empty()) return 0.0;
    return *min_element(distances.begin(), distances.end());
}

void PointSet::sortDistances()  {
    sort(distances.begin(), distances.end());

}
void PointSet::printDistances() const {
    cout << "tavolsagok listaja " << distances.size() << " db:" << endl;
    for (size_t i = 0; i < distances.size(); ++i) {
        cout << distances[i] << " | ";
    }
    cout << endl;
}


int PointSet::numDistinctDistances() {
    set<double> distinctDistances(distances.begin(), distances.end());
    return distinctDistances.size();
}

int PointSet::numDistances() const {
    int db=0;
    for (size_t i = 0; i < distances.size(); ++i) {
        db++;
    }
    return db;
}
