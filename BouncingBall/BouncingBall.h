//
// Created by 646ca on 12/13/2022.
//

//creates a circleshape object and bounce along the window bounds
#ifndef SFML_TEMPLATE_BOUNCINGBALL_H
#define SFML_TEMPLATE_BOUNCINGBALL_H
#include <iostream>
#include <SFML/Graphics.hpp>

//#include "functions.h"
class BouncingBall: public sf::CircleShape {
private:
//    sf::Vector2i windowSize = {1920, 1080};
    const float RADIUS = 70;
    const sf::Color COLOR = sf::Color::Yellow;

    const sf::Vector2f ballPosition = {100, 100};
    const sf::Vector2f ballMovement = {5.0, 5.0};

    sf::Vector2f velocity = {5.0, 5.0};
public:
    //sf::CircleShape ball;

    BouncingBall();
    //static void bouncingBall(sf::RenderWindow& window, sf::CircleShape& ball);
    void bounce();
    void bounce(const sf::RenderWindow& window);
    void bounce(const sf::Vector2i& windowSize);
//    void bounce(sf::Vector2i windowSize, const sf::CircleShape ball, sf::Vector2f& ballMovement);
//    void swap_floats(float& a, float& b);
};

#endif //SFML_TEMPLATE_BOUNCINGBALL_H
