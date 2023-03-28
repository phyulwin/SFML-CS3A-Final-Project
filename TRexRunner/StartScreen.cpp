//
// Created by 646ca on 12/15/2022.
//

#include "StartScreen.h"

StartScreen::StartScreen() {
    this->startScreenSetUp();
}

void StartScreen::screenTextSetUp() {
    start.setString(startText);
    gameName.setString(gameNameText);

    //font
    start.setFont(Fonts::getFont(MONOGRAM));
    gameName.setFont(Fonts::getFont(MONOGRAM));
    score.setFont(Fonts::getFont(MONOGRAM));
    //color
    start.setFillColor(sf::Color::White);
    gameName.setFillColor(sf::Color::White);
    score.setFillColor(sf::Color::White);
    //position
    gameName.setPosition({windowSizes.x/2, 100});
    start.setPosition({windowSizes.x/3, (windowSizes.y/2)-100});
    score.setPosition({50, 400});
    //size
    start.setCharacterSize(charSize);
    gameName.setCharacterSize(charSize);
    score.setCharacterSize(charSize);
}

void StartScreen::screenBackGroundSetUp() {
    backgroundTexture.loadFromFile("TRexRunner/Images/startscreenbg.png");
    background.setTexture(backgroundTexture);
    background.setScale(0.5, 0.7);
    //set position and size
    background.setPosition({0, 0});
}

void StartScreen::startScreenSetUp() {
    this->screenTextSetUp();
    this->screenBackGroundSetUp();
}

sf::Vector2f StartScreen::getWindowSize() const {
    return this->windowSizes;
}

void StartScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->background);
    target.draw(this->start);
    target.draw(this->gameName);
    target.draw(this->score);
}

template<class T>
bool StartScreen::isClicked(const T &obj, const sf::RenderWindow &window) {
    return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void StartScreen::changeText(sf::RenderTarget &target, const int& highscore) {
    this->setGameName();
    this->setStart();

    scoreText = "Your Score: " + std::to_string(highscore);
    score.setString(scoreText);
}

void StartScreen::setGameName() {
    this->gameNameText = "GAME OVER";
    gameName.setString(gameNameText);
}

void StartScreen::setStart() {
    this->startText = "- PRESS ENTER TO PLAY AGAIN -";
    start.setString(startText);
}

