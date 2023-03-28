//
// Created by P. Lwin on 10/19/2022.
//
//INCLUDES SFML FUNCTIONS OVERWRITE

//creates an individual card sprite and displays it on screen

#ifndef SFML_TEMPLATE_CARD_H
#define SFML_TEMPLATE_CARD_H
//include libraries
#include <iostream>
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>

//get enum data type from header files
#include "suits_struct.h"
#include "ranks_struct.h"

class CardSMFL: public sf::Drawable, sf::Transformable, sf::Image {
private:
    suits suit;
    ranks rank;

    //constant values
    const float BG_WIDTH = 60, BG_HEIGHT = 80;
    //rank character size
    const unsigned CHAR_SIZE = 10;
    //normal suit scales
    const sf::Vector2f SUITSCALE = {0.5, 0.5}, SMALLSUITSCALE = {0.25, 0.25};

    sf::RectangleShape background;
    sf::Text rank1, rank2;
    sf::Sprite suit1, suit2, suit3;
    static sf::Texture texture;
    static sf::Texture heartsTexture, diamondsTexture, spadesTexture, clubsTexture;

    void init();

    void setUpBackground();
    void setUpRank();
    void setUpSuit();
public:
    static sf::Font font;
    std::string rankToString();
    std::string suitToString();

    //SFML FUNCTIONS
    CardSMFL(suits suit, ranks rank);
    CardSMFL();

    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x , float y);
protected:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
};
#endif //SFML_TEMPLATE_CARD_H
