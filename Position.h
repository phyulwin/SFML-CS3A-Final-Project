//
// Created by 646ca on 12/8/2022.
//

#ifndef SFML_TEMPLATE_POSITION_H
#define SFML_TEMPLATE_POSITION_H
#include <cmath>
#include <SFML\Graphics.hpp>
//#include <SFML/Config.hpp>
//#include <SFML/System/NonCopyable.hpp>
//#include <SFML/Window/Event.hpp>
//#include <SFML/Window/WindowListener.hpp>

class Position {
public:
    template<class T, class S>
    static void left(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void right(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void center(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void top(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void bottom(const T& obj1, S& obj2, float spacing = 0);

    template<typename T>
    static void centerText(const T &obj, sf::Text &text);
};

#include "Position.cpp"
#endif //SFML_TEMPLATE_POSITION_H
