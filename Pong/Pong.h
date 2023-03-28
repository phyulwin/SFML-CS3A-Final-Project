//
// Created by 646ca on 12/14/2022.
//

#ifndef SCREEN_CPP_PONG_H
#define SCREEN_CPP_PONG_H
#include <SFML\Graphics.hpp>
#include <iostream>

#include "ball.h"
#include "paddle.h"

class Pong: public Ball, public Paddle {
private:

public:
    Ball circle;
    Paddle paddle;
    Paddle paddle2;

    Pong();
    bool runPong(sf::RenderWindow& window);
};
#endif //SCREEN_CPP_PONG_H
