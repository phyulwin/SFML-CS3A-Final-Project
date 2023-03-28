//
// Created by 646ca on 12/8/2022.
//

#include "Lists.h"

ListItem::ListItem() : ListItem("", {0.f, 0.f}){

}

ListItem::ListItem(std::string text, sf::Vector2f size) {
    setuptext(text);
    setupbox(size);

}

//member functions
void ListItem::setuptext(std::string text) {
    this->text.setFont(Fonts::getFont(OPEN_SANS));
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Blue);
    Position::centerText(box, this->text);
}

void ListItem::setupbox(sf::Vector2f size) {
    setBoxSize(size);
}

void ListItem::onclick(void (*f)(), sf::RenderWindow& window) {
    if(MouseEvents::isClicked(box, window)) {
        f();
    }
}

void ListItem::eventhandler(sf::RenderWindow &window, const sf::Event &event) {
    if(MouseEvents::isHovered(box, window)) {
        box.setFillColor(hoverColor);
        text.setFillColor(backgroundColor);
    } else {
        box.setFillColor(backgroundColor);
        text.setFillColor(hoverColor);
    }
}

void ListItem::update() {

}

void ListItem::setBoxSize(sf::Vector2f size) {
    box.setSize(size);
    Position::centerText(box, this->text);
}

void ListItem::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
    Position::centerText(box, this->text);
}

void ListItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN)) {
        target.draw(box);
        target.draw(text);
    }
}

sf::Text ListItem::getText() const {
    return this->text;
}

sf::FloatRect ListItem::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void ListItem::setPosition(const sf::Vector2f &position)
{
    box.setPosition(position);
    Position::centerText(box, this->text);
}

void ListItem::setPosition(float x, float y) {
    box.setPosition({x, y});
}

void ListItem::setString(std::string text) {
    this->text.setString(text);
}

std::string ListItem::getString() {
    return text.getString();
}
