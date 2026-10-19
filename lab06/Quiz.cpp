//
// Created by markt on 2026. 10. 19..
//

#include "Quiz.h"
#include <iostream>


int Quiz::counter = 1;


Quiz::Quiz(string name) : name(name), id(counter++), isReady(false) {

}


void Quiz::addItem(const QuizItem& item) {

    if (isReady) {
        cout << "Hiba: '" << name << "' kviz mar le van zarva" << endl;
        return;
    }
    items.push_back(item);
}


void Quiz::finalize() {
    isReady = true;
}


int Quiz::getId() const {
    return id;
}

string Quiz::getName() const {
    return name;
}

const vector<QuizItem>& Quiz::getItems() const {
    return items;
}

bool Quiz::getIsReady() const {
    return isReady;
}