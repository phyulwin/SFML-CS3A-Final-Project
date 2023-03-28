//
// Created by P. Lwin on 10/8/2022.
//
#ifndef SFML_TEMPLATE_BALL_H
#define SFML_TEMPLATE_BALL_H

#include <iostream>
#include <SFML\Graphics.hpp>
//in header file
class Ball: public sf::CircleShape {
private:
    sf::Vector2f velocity = {1, 1};
public:
    Ball();
    void bounce();
    void bounce(const sf::RenderWindow& window);
    void bounce(const sf::Vector2u& windowSize);
    void setVelocity(const sf::Vector2f& velocity);
};
#endif //SFML_TEMPLATE_BALL_H
