//
// Created by markt on 2026. 11. 23..
//
#include <string>
#include "Settlement.h"
#include <vector>
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#ifndef CPP_2026_SETTLEMENTSTATISTICSIMPL_H
#define CPP_2026_SETTLEMENTSTATISTICSIMPL_H

struct SettlementStatisticsImpl {
    Settlement settlements;
    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;
    virtual int numSettlementsByCounty(const string& county) const = 0;
    virtual vector<Settlement> findSettlementsByCounty(
    const string& county) const = 0;
    virtual Settlement findSettlementsByNameAndCounty(
    const string& name, const string& county) const = 0;
    virtual Settlement maxPopulationBySettlement() const = 0;
    virtual Settlement minPopulationBySettlement() const = 0;
    virtual vector<Settlement> findSettlementsByName(
    const string& name) = 0;
};


#endif //CPP_2026_SETTLEMENTSTATISTICSIMPL_H