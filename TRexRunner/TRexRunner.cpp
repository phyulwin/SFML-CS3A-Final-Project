//
// Created by 646ca on 12/15/2022.
//

#include "TRexRunner.h"

TRexRunner::TRexRunner() {
Game newgame;
    StartScreen startScreen;
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y, 60), "Kelly Lwin_T Rex Runner");
    window.setFramerateLimit(60);
    this->runGame(window, startScreen);
}

void TRexRunner::runGame(sf::RenderWindow &window, StartScreen& startScreen) {
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                //window.close(); //closes start screen
                //opens the main game
                Game newgame;
                newgame.runGame(window);

                int highscore = newgame.getScore();
                startScreen.changeText(window, highscore);
            }
        }
        window.clear(sf::Color::White);
        window.draw(startScreen);
        window.display();
    }
}
