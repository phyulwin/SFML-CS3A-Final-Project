//
// Created by 646ca on 12/8/2022.
//

#ifndef SFML_TEMPLATE_LISTS_H
#define SFML_TEMPLATE_LISTS_H
#include "Position.h"
#include "Font.h"
#include "MouseEvents.h"
#include "States.h"

#include <SFML\Graphics.hpp>

class ListItem : public sf::Drawable, public States {
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    sf::RectangleShape box;
    sf::Text text;

    float scale = 0.6f;
    void setuptext(std::string text);
    void setupbox(sf::Vector2f size);
    sf::Color backgroundColor = sf::Color::White, hoverColor = sf::Color::Blue;
public:
    ListItem();
    ListItem(std::string text, sf::Vector2f size);
    void onclick(void (* f)(), sf::RenderWindow& window);
    void eventhandler(sf::RenderWindow& window, const sf::Event& event);
    void update();

    //getter functions
    std::string getString();
    sf::Text getText() const;

    //setter functions
    void setBoxSize(sf::Vector2f size);
    void setTextSize(unsigned int size);

    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setString(std::string text);

    sf::FloatRect getGlobalBounds() const;
};
#endif //SFML_TEMPLATE_LISTS_H
