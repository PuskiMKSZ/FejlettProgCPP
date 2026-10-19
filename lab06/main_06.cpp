#include <iostream>
#include "QuizItem.h"
#include "Quiz.h"
#include <map>
#include "QuizGame.h"
#include "User.h"
int main() {

    QuizItem q1("fovaros");
    q1.addAnswer("kolozs");
    q1.addAnswer("bukarest");
    q1.addAnswer("marosvasarhely");

    q1.setCorrectAnswer(1);

    QuizItem q2("hanymasodper");
    q2.addAnswer("50");
    q2.addAnswer("60");
    q2.addAnswer("100");
    q2.setCorrectAnswer(1);


    Quiz CppQuiz("elso");
    CppQuiz.addItem(q1);
    CppQuiz.addItem(q2);
    CppQuiz.finalize();


    User player("Mark");
    QuizGame game(CppQuiz, player);
    game.GameStart();


    player.printResults();

    return 0;
}