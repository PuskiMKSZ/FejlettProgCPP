#ifndef CPP_2026_QUIZGAME_H
#define CPP_2026_QUIZGAME_H

#include "Quiz.h"
#include "User.h"

class QuizGame {
    const Quiz& quiz;
    User& user;

public:

    QuizGame(const Quiz& quiz, User& user);

    void GameStart();
};

#endif //CPP_2026_QUIZGAME_H