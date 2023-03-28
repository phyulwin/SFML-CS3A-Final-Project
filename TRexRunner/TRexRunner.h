//
// Created by 646ca on 12/15/2022.
//

#ifndef SCREEN_CPP_TREXRUNNER_H
#define SCREEN_CPP_TREXRUNNER_H
#include "Game.h"
#include "StartScreen.h" //FINAL GAME

class TRexRunner: public Game, public StartScreen {
public:
    TRexRunner();
    void runGame(sf::RenderWindow& window, StartScreen& startScreen);
};

#endif //SCREEN_CPP_TREXRUNNER_H
