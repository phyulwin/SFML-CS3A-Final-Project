//
// Created by 646ca on 12/15/2022.
//

#ifndef SFML_TEMPLATE_SCORE_H
#define SFML_TEMPLATE_SCORE_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "StartScreen.h"
#include "Font.h"

class Score: public sf::Sprite {
private:
    std::string scoreText;
    sf::Text score;
    std::string highestScoreText;
    sf::Text highestScore;
public:
    Score();

    int currentScore;
    std::vector<int> scores;
    int scoresVectorSize = 0;

    int current;
    int highest = 0;

    void setupScoreGraphics();
    int getCurrentScore() const;
    void update(sf::RenderWindow& window, sf::Time& time);
    //keep adding score while the program is running
    void scoretracker(Score& score);
    const int highestscore();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_SCORE_H
