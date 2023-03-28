//
// Created by 646ca on 12/15/2022.
//

#include "Trees.h"

Trees::Trees() : rect(0, 0, 50, 50) {
    srand(time(NULL)); //call only once
    this->setupGraphics();
    this->display = false;
}

Trees::~Trees() {
//new trees
}

void Trees::setupGraphics() {
    texture.loadFromFile("TRexRunner/Images/trees.png");
    this->trees.setTexture(texture);
    this->trees.setTextureRect(rect);
    this->trees.setPosition(originalPosition);

    position = sf::Vector2f(trees.getPosition());
}

sf::FloatRect Trees::getGlobalBounds() {
    sf::FloatRect bounds = trees.getGlobalBounds();
    return bounds;
}

void Trees::update(int frames) {
    int random = rand()%4;
    if(frames % 6 == 0 && !display) {
        switch(random) {
            case 0: rect = sf::IntRect(0, 0, 50, 50);
            break;
            case 1: rect = sf::IntRect(50, 0, 50, 50);
            break;
            case 2: rect = sf::IntRect(0, 50, 50, 50);
            break;
            default: rect = sf::IntRect(50, 50, 50, 50);
            break;
        }
        //show trees on screen
        display = true;
    }
    //in the case castus already on screen
    trees.setTextureRect(rect);
    if(display) {
        position.x = position.x - 4;
        trees.setPosition(position);
        if (position.x <= -50) {
            display = false;
            trees.setPosition(originalPosition);
        }
    }
    //always initialize again
    position = sf::Vector2f(trees.getPosition());
}

void Trees::draw(sf::RenderWindow &window) {
    window.draw(this->trees);
}
