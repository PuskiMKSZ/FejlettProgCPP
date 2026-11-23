#include "SettlementStatisticsImpl.h"
#include "Settlement.h"
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>


using namespace std;

int SettlementStatisticsImpl::numSettlements() const override{
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    int numCounties = 0;
    for (auto it = settlements.begin(); it != settlements.end(); it = settlements.upper_bound(it->first)) {
        numCounties++;
    }
    return numCounties;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string& county) const {
    int result = 0;
    for (auto it = settlements.lower_bound(county); it != settlements.upper_bound(county); it++) {
        result++;
    }
    return result;
}


