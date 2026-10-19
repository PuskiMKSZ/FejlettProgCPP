//
// Created by markt on 2026. 10. 19..
//


#ifndef CPP_2026_USER_H
#define CPP_2026_USER_H

#include <string>
#include <map>

using namespace std;

class User {
    int id;
    string name;
    map<int, double> results;

    static int counter;

public:

    User(string name);

    int getId() const;
    string getName() const;
    const map<int, double>& getResults() const;

    void addResult(int quizId, double percentage);
    void printResults() const;
};

#endif //CPP_2026_USER_H
