//
// Created by 646ca on 12/15/2022.
//

#ifndef SFML_TEMPLATE_GROUND_H
#define SFML_TEMPLATE_GROUND_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Ground : public sf::Sprite {
private:
    sf::Texture bg;
    sf::Sprite background;

    const sf::Vector2f originalPosition = {866, 550};
    sf::Vector2f position;
public:
    Ground();
    ~Ground();
    void update();
    void drawNew(sf::RenderWindow& window);
protected:
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_GROUND_H
