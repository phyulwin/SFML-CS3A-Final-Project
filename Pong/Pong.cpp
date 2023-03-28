//
// Created by 646ca on 12/14/2022.
//

#include "Pong.h"

Pong::Pong() {

}

bool Pong::runPong(sf::RenderWindow& window) {
    paddle.setPosition({100, static_cast<float>(window.getSize().y/3)});
    paddle2.setPosition({static_cast<float>(window.getSize().x-100), static_cast<float>(window.getSize().y/3)});

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
                return false;
            }
            //paddle1
            if(sf::Keyboard::isKeyPressed((sf::Keyboard::S))) {
                paddle.paddleMoveDown(window.getSize());
            }
            if(sf::Keyboard::isKeyPressed((sf::Keyboard::W))) {
                paddle.paddleMoveUp(window.getSize());
            }
            //paddle2
            if(sf::Keyboard::isKeyPressed((sf::Keyboard::Down))) {
                paddle2.paddleMoveDown(window.getSize());
            }
            if(sf::Keyboard::isKeyPressed((sf::Keyboard::Up))) {
                paddle2.paddleMoveUp(window.getSize());
            }
        }
        //set global bounds to each objects
        sf::FloatRect a = circle.getGlobalBounds();
        sf::FloatRect b = paddle.getGlobalBounds();
        sf::FloatRect c = paddle2.getGlobalBounds();
        if(a.intersects(b) || a.intersects(c)) {
            circle.bounce();
        }
        circle.bounce(window.getSize());

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(paddle);
        window.draw(paddle2);
        window.display();
    }
}
