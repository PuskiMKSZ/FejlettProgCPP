#include "User.h"
#include <iostream>

int User::counter = 1;

User::User(string name) : name(name), id(counter++) {}

int User::getId() const {
    return id;
}

string User::getName() const {
    return name;
}

const map<int, double>& User::getResults() const {
    return results;
}

void User::addResult(int quizId, double percentage) {
    results[quizId] = percentage;
}

void User::printResults() const {
    cout << name << " - eredmenyeim " << endl;
    if (results.empty()) {
        cout << "nincs  kviz." << endl;
        return;
    }
    for (const auto& entry : results) {
        cout << "Kviz ID: " << entry.first << " -eredmeny:" << entry.second << endl;
    }
}