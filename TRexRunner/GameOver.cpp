//
// Created by 646ca on 12/15/2022.
//

#include "GameOver.h"

GameOver::GameOver() {
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y, 60), "Kelly Lwin_T Rex Runner");
    window.setFramerateLimit(60);
    this->screensetup(window);
}

void GameOver::screensetup(sf::RenderWindow& window) {
    this->showOnEndGame();
    this->changeScreen();
}

void GameOver::showOnEndGame() {
    gameOver.setString(gameOverText);
    retry.setString(retryText);
    //font
    gameOver.setFont(Fonts::getFont(MONOGRAM));
    retry.setFont(Fonts::getFont(MONOGRAM));
    //color
    gameOver.setFillColor(sf::Color::White);
    retry.setFillColor(sf::Color::White);
    //position
    gameOver.setPosition({windowSize.x/2, 100});
    retry.setPosition({windowSize.x/3, (windowSize.y/2)-100});
    //size
    gameOver.setCharacterSize(textSize);
    retry.setCharacterSize(textSize-30);
}

void GameOver::changeScreen() {
    backgroundTexture.loadFromFile("TRexRunner/Images/startscreenbg.png");
    background.setTexture(backgroundTexture);
    background.setScale(0.5, 0.7);
    //set position and size
    background.setPosition({0, 0});
}

void GameOver::draw(sf::RenderWindow &window) {
    window.draw(this->gameOver);
    window.draw(this->retry);
}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->gameOver);
    target.draw(this->retry);
}
