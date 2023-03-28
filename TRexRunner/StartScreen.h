//
// Created by 646ca on 12/15/2022.
//

#ifndef SFML_TEMPLATE_STARTSCREEN_H
#define SFML_TEMPLATE_STARTSCREEN_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Font.h"

class StartScreen: public sf::Sprite, public Fonts {
private:
    std::string startText = "- PRESS Enter to START -";
    sf::Text start;

    std::string gameNameText = "T-Rex Runner";
    sf::Text gameName;

    std::string highscore = "Your Score: ";
    std::string scoreText = "";
    sf::Text score;

    sf::Sprite background;
    sf::Texture backgroundTexture;
public:
    const sf::Vector2f windowSizes = {816, 600};
    static const unsigned int charSize= 50;

    StartScreen();
    void screenTextSetUp();
    void screenBackGroundSetUp();
    void startScreenSetUp();
    sf::Vector2f getWindowSize() const;

    //mouse event
    template<class T>
    static bool isClicked(const T& obj, const sf::RenderWindow& window);

    //game over - change text
    void changeText(sf::RenderTarget &target, const int& highscore);
    void setGameName();
    void setStart();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_STARTSCREEN_H
