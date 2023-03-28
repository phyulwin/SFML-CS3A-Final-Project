//
// Created by 646ca on 12/15/2022.
//

#include "Score.h"

Score::Score() {
    currentScore = 0;
    setupScoreGraphics();
}

void Score::setupScoreGraphics() {
    score.setString(std::to_string(currentScore));
    score.setFont(Fonts::getFont(MONOGRAM));
    score.setFillColor(sf::Color::Black);
    score.setPosition({50, 50});
    score.setCharacterSize(StartScreen::charSize);

    highestScore.setString("Highest Score: " + std::to_string(highest));
    highestScore.setFont(Fonts::getFont(MONOGRAM));
    highestScore.setFillColor(sf::Color::Black);
    highestScore.setPosition({250, 50});
    highestScore.setCharacterSize(StartScreen::charSize);
}

int Score::getCurrentScore() const {
    return this->currentScore;
}

void Score::update(sf::RenderWindow &window, sf::Time& time) {
    this->currentScore += time.asMilliseconds()/6;
    score.setString(std::to_string(currentScore));
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->score);
    target.draw(this->highestScore);
}

void Score::scoretracker(Score& score) {
    //append new score
    score.scores.emplace_back(score.currentScore);
    this->scoresVectorSize++;
}

const int Score::highestscore() {
    int max = 0;
    for(int i=0; i<scores.size(); i++) {
        if(scores[i] > max) {
            max = scores[i];
        }
    }
    this->highest = max;
}
