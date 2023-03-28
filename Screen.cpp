//
// Created by 646ca on 12/8/2022.
//

#include "Screen.h"

Screen::Screen() : Screen("", "") {
    this->fillVector();
}

Screen::Screen(std::string text, std::string buttonText) :
        text(text, Fonts::getFont(OPEN_SANS), 24), button(buttonText, {200, 50}) {
    sf::RectangleShape r({720, 420});
    Position::centerText(r, this->text);
    //Position::bottom(this->text, button, 50.f);
}

void Screen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    target.draw(text);
//    target.draw(button);
}

unsigned int Screen::getWindowWidth() const {
    return WINDOW_WIDTH;
}

unsigned int Screen::getWindowHeight() const {
    return WINDOW_HEIGHT;
}

void Screen::setupgraphics(sf::RenderTarget& window) {
    //arrows
    //set texture
    arrowTexture.loadFromFile("Images/back_arrow.png");
    backArrow.setTexture(arrowTexture);
    nextArrow.setTexture(arrowTexture);
    nextArrow.rotate(180);
    openProjectButtonTexture.loadFromFile("Images/openprojectbuttontexture.png");
    openProjectButton.setTexture(openProjectButtonTexture);

    //set scale
    const float BUTTONSCALE = 0.3;
    backArrow.setScale({BUTTONSCALE, BUTTONSCALE});
    nextArrow.setScale({BUTTONSCALE, BUTTONSCALE});
    openProjectButton.setScale({0.5, 0.5});

    //set position
    backArrow.setPosition({100, 490});
    nextArrow.setPosition({WINDOW_WIDTH-100, 490});
    openProjectButton.setPosition({400, (WINDOW_HEIGHT/2)+200});

    projectName.setPosition({openProjectButton.getPosition().x, openProjectButton.getPosition().y-50});
    projectName.setFont(getFont(OPEN_SANS));
    projectName.setCharacterSize(20);
    projectName.setFillColor(sf::Color::Black);
    projectImage.setPosition({400, 50});
    const float IMAGESCALE = 0.7;
    projectImage.setScale({IMAGESCALE, IMAGESCALE});
}

void Screen::setProjectImage(const int projectIndex) {
    //this should be in update function
    switch(projectIndex) {
        case 1: projectImageTexture.loadFromFile("Images/greencircle.png"); break;
        case 2: projectImageTexture.loadFromFile("Images/bouncingball.png"); break;
        case 3: projectImageTexture.loadFromFile("Images/pong.png"); break;
        case 4: projectImageTexture.loadFromFile("Images/tophatguy.png"); break;
        case 5: projectImageTexture.loadFromFile("Images/card.png"); break;
        case 6: projectImageTexture.loadFromFile("Images/pokeranalysis.png"); break;
        default: projectImageTexture.loadFromFile("Images/trexrunner.png"); break;
    }
    projectImage.setTexture(projectImageTexture);
}

void Screen::setProjectName(const int projectIndex) {
    projectName.setString("- " + projectString[projectIndex] + " -");
    //projectName.setString(getProjectName(getProject(projectIndex)));
    //std::cout << projectString[projectIndex] << std::endl;
}

projectsEnum Screen::getProject(const int i) {
    switch(i) {
        case 1: return projectsEnum::GREEN_CIRCLE;
        case 2: return projectsEnum::BOUNCING_BALL;
        case 3: return projectsEnum::PONG;
        case 4: return projectsEnum::TOP_HAT_GUY;
        case 5: return projectsEnum::CARD;
        case 6: return projectsEnum::POKER_ANALYSIS;
        default: return projectsEnum::TREX_RUNNER;
    }
}

std::string Screen::getProjectName(const projectsEnum project) {
    switch(project) {
        case 1: return "GREEN CIRCLE";
        case 2: return "BOUNCING BALL";
        case 3: return "PONG";
        case 4: return "TOP HAT GUY";
        case 5: return "CARD";
        case 6: return "POKER ANALYSIS";
        default: return "T-REX RUNNER";
    }
}

void Screen::fillVector() {
    for(int i=0; i<PROJECT_COUNT; i++) {
        projects.push_back(Screen::getProject(i+1));
    }
    for(int i=0; i<PROJECT_COUNT; i++) {
        projectString.push_back(getProjectName(getProject(i+1)));
    }
    projectString.emplace_back("T-REX RUNNER");
    this->setProjectImage(1);
    this->setProjectName(1);
}