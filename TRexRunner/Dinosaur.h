//
// Created by 646ca on 12/15/2022.
//

#ifndef SFML_TEMPLATE_DINOSAUR_H
#define SFML_TEMPLATE_DINOSAUR_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Trees.h"

class Dinosaur: public sf::RectangleShape {
private:
    sf::Vector2f position;
    sf::Vector2f velocity = {0, 0};
    sf::Vector2f gravity = {0, 0.98};
    sf::IntRect rect;

    sf::Texture dinosaurTexture;
    sf::Sprite dinosaur;

    int movement = 0;
    bool jump = false;
    bool ground = true;
public:
    Dinosaur();

    void setupGraphicsDino();

    sf::FloatRect getGlobalBounds();
    //note - cannot use sf drawable
    void draw(sf::RenderWindow& window);
    void update(int frames, Trees trees);
    void eventListener();
};


#endif //SFML_TEMPLATE_DINOSAUR_H
