//
// Created by P. Lwin on 10/20/2022.
//
#include "paddle.h"
//pong
//default constructor
Paddle::Paddle() {
    //shape yourself like a pong paddle
    setSize({30, 100});
    setFillColor(sf::Color::Yellow);
    setPosition({0, 420/3});
}
void Paddle::paddleMove(const sf::RenderWindow& window) {
}

void Paddle::paddleMoveDown(const sf::Vector2u& windowSize) {
    setVelocity({0, -5});
    sf::FloatRect b = getGlobalBounds();
    if(b.top + b.height >= windowSize.y) {
        velocity.y = 0;
    }
    else {
        velocity.y *= -1;
    }
    sf::RectangleShape::move(velocity);
}

void Paddle::paddleMoveUp(const sf::Vector2u& windowSize) {
    setVelocity({0, 5});
    sf::FloatRect b = getGlobalBounds();
    if(b.top <= 0) {
        velocity.y = 0;
    }
    else {
        velocity.y *= -1;
    }
    sf::RectangleShape::move(velocity);
}

void Paddle::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}