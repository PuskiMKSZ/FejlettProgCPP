#include "QuizItem.h"
#include <utility>

int QuizItem::counter = 0;


QuizItem::QuizItem(string question) : question(question), id(counter++), correctAnswer(-1) {

}


int QuizItem::getId() const {
    return id;
}

string QuizItem::getQuestion() const {
    return question;
}

vector<string> QuizItem::getAnswers() const {
    return answers;
}

int QuizItem::getCorrectAnswer() const {
    return correctAnswer;
}
void QuizItem::addAnswer(string answer) {
    this->answers.push_back(answer);
}

void QuizItem::setCorrectAnswer(int correctAnswer) {
    this->correctAnswer = correctAnswer;
}



