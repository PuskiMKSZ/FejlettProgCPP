#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "Settlement.h"

using namespace std;


int main() {
    multimap<string,Settlement> settlements;
    ifstream ifs("telepulesek.csv");
    if (!ifs) throw runtime_error("Error opening file");
    string line;
    getline( ifs, line);
    while (getline(ifs,line)) {
        stringstream ss(line);
        string name,county;
        int population;
        getline(ss, name, ',');
        getline(ss, county, ',');
        ss >> population;

        settlements.emplace(county, Settlement(name, county, population));
    }
    cout<< settlements.size()<<endl;


    string county="MS";

    cout<<"MS-ek szama: "<< result<<endl;

    return 0;
}