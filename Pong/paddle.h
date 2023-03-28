//
// Created by P. Lwin on 10/20/2022.
//

#ifndef SFML_TEMPLATE_PADDLE_H
#define SFML_TEMPLATE_PADDLE_H
#include <iostream>
#include <SFML\Graphics.hpp>
//pong game
class Paddle: public sf::RectangleShape {
private:
    sf::Vector2f velocity = {0, 2};
public:
    //create default constructor
    Paddle();
    void paddleMove(const sf::RenderWindow& window);

    void paddleMoveDown(const sf::Vector2u& windowSize);
    void paddleMoveUp(const sf::Vector2u& windowSize);

    void setVelocity(const sf::Vector2f& velocity);
};
#endif //SFML_TEMPLATE_PADDLE_H
