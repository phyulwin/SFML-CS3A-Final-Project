//
// Created by 646ca on 12/12/2022.
//

#ifndef SFML_TEMPLATE_POKERANALYSIS_H
#define SFML_TEMPLATE_POKERANALYSIS_H
#include <iostream>
#include <SFML\Graphics.hpp>

//creates a card hand object and draws the hands on the screen
#include "CardHand_Cards.h"
class PokerAnalysis: public sf::Drawable {
public:
    PokerAnalysis();
protected:
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_POKERANALYSIS_H
