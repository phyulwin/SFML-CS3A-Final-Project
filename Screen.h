//
// Created by 646ca on 12/8/2022.
//

#ifndef SFML_TEMPLATE_SCREEN_H
#define SFML_TEMPLATE_SCREEN_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Lists.h"
#include "States.h"
#include "Font.h"
#include "Position.h"

class Screen: public sf::Sprite, public States, public Fonts {
public:
    static const unsigned int WINDOW_WIDTH = 1920, WINDOW_HEIGHT = 1080;

    const int PROJECT_COUNT = 7;
    sf::Text text;
    ListItem button;

    std::vector<sf::Sprite> portfolioAssets;
    sf::Sprite nextArrow;
    sf::Sprite backArrow;
    sf::Sprite openProjectButton;

    sf::Sprite projectImage;
    sf::Text projectName;
private:
    sf::Texture arrowTexture;
    sf::Texture openProjectButtonTexture;

    sf::Texture projectImageTexture;
public:
    std::vector<projectsEnum> projects;
    std::vector<std::string> projectString;

    Screen(); //gives text for text and button for button
    Screen(std::string text, std::string buttonText);

    unsigned int getWindowWidth() const;
    unsigned int getWindowHeight() const;
    void setupgraphics(sf::RenderTarget& window);

    void setProjectImage(const int projectIndex);
    void setProjectName(const int projectIndex);

    static projectsEnum getProject(const int i);
    static std::string getProjectName(const projectsEnum project);
    void fillVector();
protected:
    //void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif //SFML_TEMPLATE_SCREEN_H
