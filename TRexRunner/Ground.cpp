//
// Created by 646ca on 12/15/2022.
//

#include "Ground.h"

Ground::Ground() {
    bg.loadFromFile("TRexRunner/Images/ground.png");
    bg.setRepeated(1);
    background.setTexture(bg);

    background.setOrigin(0, 0);
    background.scale(1.5, 2);
    background.setTextureRect(sf::IntRect(0, 0, 1632, 26));
    background.setPosition(0, 574);

    position = sf::Vector2f(background.getPosition());
}

Ground::~Ground() {
//in case ground runs out
}

void Ground::update() {
    position.x -= 4;
    if (position.x == originalPosition.x * -1) {
        position.x = 0;
    }
    background.setPosition(position);
    position = sf::Vector2f(background.getPosition());
}

void Ground::drawNew(sf::RenderWindow &window) {
    window.draw(background);
}

void Ground::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
}
