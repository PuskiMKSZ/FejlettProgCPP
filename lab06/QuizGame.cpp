#include "QuizGame.h"
#include <iostream>

QuizGame::QuizGame(const Quiz& quiz, User& user) : quiz(quiz), user(user) {}

void QuizGame::GameStart() {
    if (!quiz.getIsReady()) {
        cout << "Quiz" << quiz.getName() << " n " << endl;
        return;
    }

    const auto& items = quiz.getItems();

    cout << "\nKezdes " << quiz.getName() << " " << endl;


    int correctCount = 0;

    for (size_t i = 0; i < items.size(); ++i) {
        const auto& item = items[i];
        cout << i + 1 << "kerdes: " << item.getQuestion() << endl;

        const auto& answers = item.getAnswers();
        for (size_t j = 0; j < answers.size(); ++j) {
            cout << "  " << j + 1 << ") " << answers[j] << endl;
        }

        int userAnswer = -1;
        cout << "valasz lehetoseg : " << answers.size()<< endl;
        cout << "valasz:" ;
        cin >> userAnswer;

        // Convert 1-based index input to 0-based index
        if (userAnswer - 1 == item.getCorrectAnswer()) {
            cout << " Helyes" << endl;
            correctCount++;
        } else {
            cout << "Helytelen" << endl;
        }
        cout << "-----------------------------------" << endl;
    }

    double percentage = (static_cast<double>(correctCount) / items.size()) * 100.0;


    user.addResult(quiz.getId(), percentage);
}