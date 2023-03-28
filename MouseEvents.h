//
// Created by 646ca on 12/8/2022.
//

#ifndef SFML_TEMPLATE_MOUSEEVENTS_H
#define SFML_TEMPLATE_MOUSEEVENTS_H
#include <SFML\Graphics.hpp>

class MouseEvents {
private:

public:
    template<class T>
    static bool isHovered(const T& obj, const sf::RenderWindow& window);
    template<class T>
    static bool isClicked(const T& obj, const sf::RenderWindow& window);
    template<class T>
    static bool isNotClicked(const T& obj, const sf::RenderWindow& window);
};

#include "MouseEvents.cpp"
#endif //SFML_TEMPLATE_MOUSEEVENTS_H
