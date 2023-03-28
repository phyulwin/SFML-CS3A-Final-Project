//
// Created by 646ca on 12/13/2022.
//

#include "BouncingBall.h"
BouncingBall::BouncingBall() {
    setRadius(RADIUS);
    setFillColor(sf::Color::Yellow);
    setOrigin(RADIUS, RADIUS); //define ball center point from the corner
    setPosition(ballPosition);
}

void BouncingBall::bounce(const sf::RenderWindow &window) {

}

void BouncingBall::bounce() {
    velocity.x *= -1;
}

void BouncingBall::bounce(const sf::Vector2i& windowSize) {
    sf::FloatRect b = getGlobalBounds();
    if(b.top + b.height >= windowSize.y || b.top <= 0) {
        velocity.y *= -1;
    }
	if(b.left + b.width >= windowSize.x || b.left <= 0) {
		velocity.x *= -1;
	}
    sf::CircleShape::move(velocity);
}

/*
void BouncingBall::bounce(sf::Vector2i windowSize, const sf::CircleShape ball, sf::Vector2f& ballMovement) {
    //using the momentum equation p1 = p2, switch x and y if the ball hits either one of the four walls
    //from top left corner
    //if the ball hits the right wall
    if(ball.getPosition().x > windowSize.x-ball.getRadius()) {
        swap_floats(ballMovement.x, ballMovement.y);
    }
        //else if the ball hits the left wall
    if(ball.getPosition().x < ball.getRadius()) {
        swap_floats(ballMovement.y, ballMovement.x);
    }
        //else if the ball hits the top wall
    if(ball.getPosition().y < ball.getRadius()) {
        swap_floats(ballMovement.y, ballMovement.x);
    }
        //else if the ball hits the bottom wall
    if(ball.getPosition().y > windowSize.y-ball.getRadius())
    {
        swap_floats(ballMovement.x, ballMovement.y);
    }
    this->bounce(windowSize);
    return;
//    ball.move(ballMovement.x, ballMovement.y);
}

void BouncingBall::swap_floats(float& a, float& b) {
    float temp = a;
    a = -b;
    b = temp;
}*/