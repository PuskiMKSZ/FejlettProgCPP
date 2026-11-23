//
// Created by markt on 2026. 11. 23..
//

#include "Settlement.h"

#include <ostream>
using namespace std;

Settlement::Settlement(const string &name, const string &county, int population): name(name), county(county), population(population){}

const string &Settlement::getName() const {
    return name;
}
void Settlement::setName(const string &name) {
    this->name = name;
}

const string &Settlement::getCounty() const {
    return county;
}

void Settlement::setCounty(const string &county) {
    this->county = county;
}

int Settlement::getPopulation() const {
    return population;
}
void Settlement::setPopulation(int population) {
    this->population = population;
}


std::ostream & operator<<(std::ostream &os, const Settlement &obj) {
    return os
           << "name: " << obj.name
           << " county: " << obj.county
           << " population: " << obj.population;
}
int Settlement::size() const {
    for
}
