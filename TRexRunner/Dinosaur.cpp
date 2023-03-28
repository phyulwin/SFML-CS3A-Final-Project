//
// Created by 646ca on 12/15/2022.
//

#include "Dinosaur.h"

Dinosaur::Dinosaur() : rect(0, 0, 50, 50) {
    this->setupGraphicsDino();
}

void Dinosaur::setupGraphicsDino() {
    dinosaurTexture.loadFromFile("TRexRunner/Images/dinosaur.png");
    dinosaur.setTexture(dinosaurTexture);
    dinosaur.setTextureRect(rect);
    dinosaur.setPosition(80, 550);

    //get position
    position = sf::Vector2f(dinosaur.getPosition());
}
sf::FloatRect Dinosaur::getGlobalBounds() {
    sf::FloatRect bounds = dinosaur.getGlobalBounds();
    return bounds;
}

void Dinosaur::draw(sf::RenderWindow &window) {
    window.draw(dinosaur);
}

void Dinosaur::update(int frames, Trees trees) {
    position += velocity;
    if(ground) {
        velocity = {0, 0};
    }
    if (!ground) {
        velocity += gravity;
        if (position.y >= 550) {
            position.y = 550;
            ground = true;
            jump = false;
            velocity.y = 0;
        }
    }
    rect = sf::IntRect(movement, 0, 50, 43);
    if (frames % 12 == 0) {
        movement = (movement + 50) % 100;
    }
    dinosaur.setTextureRect(rect);
    dinosaur.setPosition(position);
}

void Dinosaur::eventListener() {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ground) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ground))
    {
        velocity.y = -20;
        jump = true;
        ground = false;
    }
}
