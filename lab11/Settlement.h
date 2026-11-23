//
// Created by markt on 2026. 11. 23..
//

#ifndef CPP_2026_SETTLEMENT_H
#define CPP_2026_SETTLEMENT_H
#include <ostream>
#include <string>
using namespace std;
class Settlement {
    string name = "";
    string county = "";
    int population = 0;
    // constructor, getters, setters, inserter operator
    public:
    Settlement(const string& name, const string& county, int population);

    const string& getName() const;
    void setName(const string& name );

    const string& getCounty() const;
    void setCounty(const string& county);

    int getPopulation() const;
    void setPopulation(int population);

    friend std::ostream & operator<<(std::ostream &os, const Settlement &obj);

    int size() const;
};

#endif //CPP_2026_SETTLEMENT_H