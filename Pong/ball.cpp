//
// Created by P. Lwin on 10/8/2022.
//
#include "ball.h"

Ball::Ball() {
    setRadius(30);
    setFillColor(sf::Color::Yellow);
    setPosition({100, 100});
    setVelocity({5.0, 5.0});
}

void Ball::bounce(const sf::RenderWindow& window) {
}

void Ball::bounce() {
    velocity.x *= -1;
    //bounce the opposite direction if collide with another object
}
void Ball::bounce(const sf::Vector2u& windowSize) {
	sf::FloatRect b = getGlobalBounds();
	if(b.top + b.height >= windowSize.y || b.top <= 0) {
		velocity.y *= -1;
	}
	if(b.left + b.width >= windowSize.x || b.left <= 0) {
        setPosition({100, 100});
		velocity.x *= -1;
	}
    sf::CircleShape::move(velocity);
}
void Ball::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}


