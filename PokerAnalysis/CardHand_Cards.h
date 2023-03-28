//
// Created by P. Lwin on 11/13/2022.
//
#ifndef SFML_TEMPLATE_CARDHAND_CARDS_H
#define SFML_TEMPLATE_CARDHAND_CARDS_H

#include "Card.h"
#include "calculateOutput.h"

//checsk the hand calculates the output for card hand
class CardHand_Cards: public CardSMFL, public CalculateOutput {
private:
    const int CARD_COUNT = 5;
    sf::Text scoreType, percentage;

    //append cards to each individual vectors
    void appendRoyalFlushCards();
    void appendStraightFlushCards();
    void appendFourOfAKindCards();
    void appendFullHouseCards();
    void appendFlushCards();
    void appendStraightCards();
    void appendThreeOfAKindCards();
    void appendTwoPairCards();
    void appendOnePairCards();
    void appendHighCardCards();

    std::vector<double> scoresPercentage;
public:
    //create sample cardHand types and set the positions of five cards relative to one another
    std::vector<CardSMFL> royalFlushCards;
    std::vector<CardSMFL> straightFlushCards;
    std::vector<CardSMFL> fourOfAKindCards;
    std::vector<CardSMFL> fullHouseCards;
    std::vector<CardSMFL> flushCards;
    std::vector<CardSMFL> straightCards;
    std::vector<CardSMFL> threeOfAKindCards;
    std::vector<CardSMFL> twoPairCards;
    std::vector<CardSMFL> onePairCards;
    std::vector<CardSMFL> highCardCards;

    CardHand_Cards();
    void appendCards();
    void arrangeCards(); //create cardHand objects
    void setCardPositions(std::vector<CardSMFL>& cardHand, sf::Vector2f positionOfHand) const;

    //string output for score type and odds of getting the score
    //try using string concat for
    const unsigned FONT_SIZE = 12;
    sf::Text royalFlushText, straightFlushText, fourOfAKindText, fullHouseText,
            flushText, straightText, threeOfAKindText, twoPairText, onePairText, highCardText;
    void textDisplayForScores();
//protected:
//    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};
#endif //SFML_TEMPLATE_CARDHAND_CARDS_H
