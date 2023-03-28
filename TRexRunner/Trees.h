//
// Created by 646ca on 12/15/2022.
//

#ifndef SFML_TEMPLATE_TREES_H
#define SFML_TEMPLATE_TREES_H
#include <time.h> //for random tree
#include <stdlib.h>
#include <SFML/Graphics.hpp>

class Trees: public sf::RectangleShape {
private:
    sf::Texture texture;
    sf::Sprite trees;
    sf::IntRect rect;

    const sf::Vector2f originalPosition = {866, 550};
    sf::Vector2f position;
    bool display = false;
public:
    Trees();
    ~Trees();
    sf::FloatRect getGlobalBounds(); //override function for sprite
    void setupGraphics();
    void update(int frames);
    void draw(sf::RenderWindow& window);
};


#endif //SFML_TEMPLATE_TREES_H
