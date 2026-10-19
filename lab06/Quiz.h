//
// Created by markt on 2026. 10. 19..
//

#ifndef CPP_2026_QUIZ_H
#define CPP_2026_QUIZ_H

#include <string>
#include <vector>
#include "QuizItem.h"

using namespace std;

class Quiz {
    int id;
    string name;
    vector<QuizItem> items;
    bool isReady=false;

    static int counter;

public:

    Quiz(string name);


    void addItem(const QuizItem& item);
    void finalize();


    int getId() const;
    string getName() const;
    const vector<QuizItem>& getItems() const;
    bool getIsReady() const;
};

#endif //CPP_2026_QUIZ_H
