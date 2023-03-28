//
// Created by 646ca on 12/10/2022.
//

#ifndef SFML_TEMPLATE_RUNPROGRAM_H
#define SFML_TEMPLATE_RUNPROGRAM_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "GreenCircle/GreenCircleClass.h"
#include "BouncingBall/BouncingBall.h"
#include "Pong/Pong.h"
#include "TopHatGuy/TopahatGuy.h"
#include "PokerAnalysis/Card.h"
#include "PokerAnalysis/PokerAnalysis.h"
#include "TRexRunner/TRexRunner.h" //FINAL GAME

class RunProgram: public Screen, public GreenCircle, public BouncingBall,
        public Pong, public TophatGuy, public Card, public PokerAnalysis,
        public TRexRunner {
private:
    static const int TOTAL_PROJECTS = 7;
public:
    RunProgram();
    void switchProject(sf::RenderWindow& window, const int projectIndex);
    void runPortfolio(sf::RenderWindow& window, const bool& portfolio, const int newProjectIndex); //use recursion

private:
    static void runGreenCircle(sf::RenderWindow& window);
    static void runBouncingBall(sf::RenderWindow& window);
    static void runPong(sf::RenderWindow& window);
    static void runTopHatGuy(sf::RenderWindow& window);
    static void runCard(sf::RenderWindow& window);
    static void runPokerAnalysis(sf::RenderWindow& window);
    static void runTrexRunner(sf::RenderWindow& window);

    static void eventHandler(sf::RenderWindow& window, sf::Event& event);
    template<class T>
    static void windowEvent(sf::RenderWindow& window, const T& obj);
    static void loadProject(sf::RenderWindow& window, const int& projectIndex);
};

#endif //SFML_TEMPLATE_RUNPROGRAM_H
