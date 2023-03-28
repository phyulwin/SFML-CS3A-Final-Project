//
// Created by 646ca on 12/10/2022.
//
#include "RunProgram.h"

RunProgram::RunProgram() {
    //default constructor
    sf::RenderWindow window(sf::VideoMode(Screen::WINDOW_WIDTH, Screen::WINDOW_HEIGHT, 32), "Kelly Portfolio");
    window.setFramerateLimit(60);
    this->runPortfolio(window, true, 1);
}

void RunProgram::eventHandler(sf::RenderWindow& window, sf::Event& event) {
    if (event.type == sf::Event::Closed){
        window.close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
        RunProgram portfolio;
    }
}

void RunProgram::switchProject(sf::RenderWindow& window, const int projectIndex) {
    this->setProjectImage(projectIndex);
    this->setProjectName(projectIndex);
}

void RunProgram::runPortfolio(sf::RenderWindow& window, const bool& portfolio, const int newProjectIndex) {
    if(portfolio) {
        std::vector<Screen> screens;
        Screen::setupgraphics(window);
        for(int i=0; i<TOTAL_PROJECTS; i++) {
            screens.emplace_back("Screen " + std::to_string(i+1), "Button " + std::to_string(i+1));
        }
        auto iter = screens.begin();
        int projectIndex = 1;
        while(window.isOpen())
        {
            sf::Event event;
            while(window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                if(MouseEvents::isClicked(this->backArrow, window) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
                    //std::cout << "go to previous project" << std::endl;
                    if(iter != screens.begin() && projectIndex != 1) {
                        --iter; projectIndex--;
                        switchProject(window, projectIndex);
                    }
                }
                if(MouseEvents::isClicked(this->nextArrow, window) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
                    //std::cout << "go to next project" << std::endl;
                    if(iter != screens.end()-1 && projectIndex != TOTAL_PROJECTS) {
                        ++iter; projectIndex++;
                        switchProject(window, projectIndex);
                    }
                }
                if(MouseEvents::isClicked(openProjectButton, window)) {
                    runPortfolio(window, false, projectIndex); //RECURSION
                    std::cout << "running project: " + getProjectName(getProject(projectIndex+1)) << std::endl;
                    //check the selected project and run the project on same window
                    //call one function here that runs the project
                    //ESCAPE OPTION SHOULD BE IN NEW PROJECT WINDOW
                }
            }
//            window.clear({43, 39, 65});
            window.clear(sf::Color::White);
            window.draw(*iter);
            window.draw(projectName);
            window.draw(projectImage);
            //draw sprites on screen
            window.draw(backArrow);
            window.draw(nextArrow);
            window.draw(openProjectButton);

            window.display();
        }
    } else {
        loadProject(window, newProjectIndex);
    }
}


void RunProgram::runGreenCircle(sf::RenderWindow &window) {
    GreenCircle circle;
    windowEvent(window, circle);
}


void RunProgram::runBouncingBall(sf::RenderWindow &window) {
    BouncingBall bouncingBall;
    const sf::Vector2f ballMovement = {5.0, 5.0};
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            RunProgram::eventHandler(window, event);
        }
        //bouncingBall.bounce({WINDOW_WIDTH, WINDOW_HEIGHT}, bouncingBall.ball, const_cast<sf::Vector2f &>(ballMovement));
        //bouncingBall.move(5.0, 5.0);
        bouncingBall.bounce({WINDOW_WIDTH, WINDOW_HEIGHT});

        window.clear(sf::Color::Black);
        window.draw(bouncingBall);
        window.display();
    }
}

void RunProgram::runPong(sf::RenderWindow &window) {
    Pong pong;
    bool runningPong = true;
    while(runningPong) {
        runningPong = pong.runPong(window);
    }
    RunProgram portfolio;
}

void RunProgram::runTopHatGuy(sf::RenderWindow &window) {
    TophatGuy t;
    t.setPosition({300, 170});
    t.setHatColor(sf::Color::Green);
    t.setBeardColor(sf::Color::Red);
    windowEvent(window, t);
}

void RunProgram::runCard(sf::RenderWindow &window) {
    CardSMFL card(DIAMONDS, THREE);
    card.setPosition({140,120});
    windowEvent(window, card);
}

void RunProgram::runPokerAnalysis(sf::RenderWindow &window) {
    srand(time(NULL));
    CardHand_Cards cards; //create an object for all sample cards output
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            RunProgram::eventHandler(window, event);
            if(sf::Event::Closed == event.type)
                window.close();
        }
        window.clear(sf::Color::Black);
        for(int i=0; i<5; i++) {
            //DRAW CARDS ON THE LEFT
            window.draw(cards.royalFlushCards[i]); window.draw(cards.royalFlushText);
            window.draw(cards.straightFlushCards[i]); window.draw(cards.straightFlushText);
            window.draw(cards.fourOfAKindCards[i]); window.draw(cards.fourOfAKindText);
            window.draw(cards.fullHouseCards[i]); window.draw(cards.fullHouseText);
            window.draw(cards.flushCards[i]); window.draw(cards.flushText);
            //DRAW CARDS ON THE RIGHT
            window.draw(cards.straightCards[i]); window.draw(cards.straightText);
            window.draw(cards.threeOfAKindCards[i]); window.draw(cards.threeOfAKindText);
            window.draw(cards.twoPairCards[i]); window.draw(cards.twoPairText);
            window.draw(cards.onePairCards[i]); window.draw(cards.onePairText);
            window.draw(cards.highCardCards[i]); window.draw(cards.highCardText);
        }
        window.display();
    }
}

void RunProgram::runTrexRunner(sf::RenderWindow &window) {
    //Game newgame;
    TRexRunner game;
}

template<class T>
void RunProgram::windowEvent(sf::RenderWindow &window, const T &obj) {
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            RunProgram::eventHandler(window, event);
        }
        window.clear(sf::Color::Black);
        window.draw(obj);
        window.display();
    }
}

void RunProgram::loadProject(sf::RenderWindow &window, const int &projectIndex) {
    switch(projectIndex) {
        case 1: runGreenCircle(window); break;
        case 2: runBouncingBall(window); break;
        case 3: runPong(window); break;
        case 4: runTopHatGuy(window); break;
        case 5: runCard(window); break;
        case 6: runPokerAnalysis(window); break;
        default: runTrexRunner(window); break;
    }
}
