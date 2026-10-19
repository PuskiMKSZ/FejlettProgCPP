//
// Created by markt on 2026. 10. 19..
//

#ifndef CPP_2026_QUIZITEM_H
#define CPP_2026_QUIZITEM_H

#include <string>
#include <vector>
#include <utility>

using namespace std;

class QuizItem {

    int id;
    string question;
    vector<string> answers;
    int correctAnswer;


    static int counter;

public:

    QuizItem(string question );
    int getId() const;
    string getQuestion() const;
    vector<string> getAnswers() const;
    int getCorrectAnswer() const;
    void addAnswer(string answer);

    void setCorrectAnswer(int correctAnswer);
};

#endif //CPP_2026_QUIZITEM_H
