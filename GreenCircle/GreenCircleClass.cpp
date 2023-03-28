//
// Created by 646ca on 12/12/2022.
//

#include "GreenCircleClass.h"
GreenCircle::GreenCircle() {
    this->circleShape.setFillColor(sf::Color::Green);
    this->circleShape.setRadius(250.f);
}

void GreenCircle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->circleShape);
}