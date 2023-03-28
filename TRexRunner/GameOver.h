//
// Created by 646ca on 12/15/2022.
//

#ifndef SFML_TEMPLATE_GAMEOVER_H
#define SFML_TEMPLATE_GAMEOVER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Font.h" //take from home directory

class GameOver: public sf::Sprite, public Fonts {
private:
    std::string retryText = "- PRESS ENTER TO PLAY AGAIN -";
    std::string gameOverText = "GAME OVER";

    static const unsigned int textSize = 80;

    sf::Sprite background;
    sf::Texture backgroundTexture;
public:
    sf::Text retry, gameOver;
    const sf::Vector2f windowSize = {816, 600};

    GameOver();
    void screensetup(sf::RenderWindow& window);
    void showOnEndGame();
    void changeScreen();

    void draw(sf::RenderWindow& window);
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif //SFML_TEMPLATE_GAMEOVER_H
