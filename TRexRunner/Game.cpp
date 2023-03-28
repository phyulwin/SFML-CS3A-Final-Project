//
// Created by 646ca on 12/6/2022.
//
#include "Game.h"
Game::Game() {
    //create main game window
    const sf::Vector2f windowSize = {816, 600};
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y, 60), "Kelly Lwin_T Rex Runner");
    window.setFramerateLimit(60);
    //start the game
    frames = 0;
    //runGame(window);
}

Game::~Game() {

}

bool Game::runGame(sf::RenderWindow& window) {
    sf::Time time1 = clock.getElapsedTime();
    Score score;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        ground.update();
        trees.update(frames);
        dinosaur.eventListener();
        dinosaur.update(frames , trees);
        //calculate frame for every movement
        frames = ((frames+1)%60)+1;
//
//if they collide --> GAME OVER
        if(dinosaur.getGlobalBounds().intersects(trees.getGlobalBounds())) {
            setScore(score.getCurrentScore()); //set final score
            //std::cout << "game over" << std::endl;
            sf::Time time2 = clock.restart();
            return false;
//            window.close();
//            GameOver gameOver;
        }
        window.clear(sf::Color::White);
        score.update(window, time1);
        window.draw(score);

//        window.draw(ground);
        ground.drawNew(window);
        trees.draw(window);
        dinosaur.draw(window);
        window.display();
    }
}

void Game::gameover(sf::RenderWindow& window, Score& score) {
    GameOver gameOver1;
    //freezes dinosaur and the ground
    //display game over text on screen
    gameOver1.draw(window);
    //display current score
    Score::scoretracker(score);
    //call eventListener for new game
    eventListener(window);
}

void Game::eventListener(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            window.close(); //closes start screen
            //opens the main game
            Game newgame;
        }
    }
}

int Game::getScore() const {
    return this->score;
}

void Game::setScore(const int score) {
    this->score = score;
}
