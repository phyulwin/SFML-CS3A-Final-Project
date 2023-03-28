//code files made on this computer
/*
#include "Game.h"
#include "StartScreen.h"

int main()
{
    //Game newgame;
    StartScreen startScreen;
    sf::Vector2f windowSize = startScreen.getWindowSize();
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y, 60), "Kelly Lwin_T Rex Runner");
    window.setFramerateLimit(60);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                //window.close(); //closes start screen
                //opens the main game
                Game newgame;
//                std::cout << "welcome back";
//                GameOver gameOver;
                std::cout << newgame.getScore() << std::endl;
                int highscore = newgame.getScore();
                startScreen.changeText(window, highscore);
            }
        }
        window.clear(sf::Color::White);
        window.draw(startScreen);
        window.display();
    }

    return 0;
} */