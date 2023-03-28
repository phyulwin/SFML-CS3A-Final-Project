//
// Created by 646ca on 12/15/2022.
//

#ifndef SFML_TEMPLATE_GAME_H
#define SFML_TEMPLATE_GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>

#include "Score.h"
#include "Dinosaur.h"
#include "Ground.h"
#include "GameOver.h"

class Game : public Score, public GameOver {
private:
    sf::RenderWindow window;
    Dinosaur dinosaur;
    Ground ground;
    //Obstacles enemy;
    Trees trees;
    int frames;

    sf::Clock clock;
    int score;
public:
    Game();
    ~Game();
    bool runGame(sf::RenderWindow& window); //return score when game over

    int getScore() const;
    void setScore(const int score);

    bool gameRunning = true;
    void gameover(sf::RenderWindow& window, Score& score);
    void eventListener(sf::RenderWindow& window);
};

#endif //SFML_TEMPLATE_GAME_H
