//
// Created by P. Lwin on 10/19/2022.
//

#ifndef SFML_TEMPLATE_TOPAHATGUY_H
#define SFML_TEMPLATE_TOPAHATGUY_H

#include <iostream>
#include <SFML\Graphics.hpp>

class TophatGuy : public sf::Drawable,  public sf::Transformable {
private:
    //create objects for tophatguy object
    sf::RectangleShape top, brim;
    sf::CircleShape face;
    sf::CircleShape triangle;

    //constant sizes for object
    const int FACE_SIZE = 30;
    const sf::Vector2f HAT_TOP_SIZE = {50, 70}, HAT_BRIM_SIZE = {100, 5};
    const int TRIANGLE_SIZE = 30;

    //constant positions for objects
    const sf::Vector2f FACE_POS = {220, 170},
        TOP_POS = {5, -60},
        BRIM_POS = {-20, 10},
        BEARD_POS = {60, 95};
public:
    TophatGuy();
    void setHatColor(const sf::Color &color);
    void setFaceColor(const sf::Color &color);
    void setBeardColor(const sf::Color &color);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    //function overload: this prompts the user to set the position of the tophatguy object
    void setPosition();
};

#endif //SFML_TEMPLATE_TOPAHATGUY_H
