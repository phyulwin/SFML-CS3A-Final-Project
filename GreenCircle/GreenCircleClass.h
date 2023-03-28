//
// Created by 646ca on 12/12/2022.
//

//creates a circle shape object and displays it on screen
#ifndef SFML_TEMPLATE_GREENCIRCLECLASS_H
#define SFML_TEMPLATE_GREENCIRCLECLASS_H
#include <iostream>
#include <SFML\Graphics.hpp>
class GreenCircle: public sf::Drawable {
private:
    sf::CircleShape circleShape;
public:
    GreenCircle();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_GREENCIRCLECLASS_H
