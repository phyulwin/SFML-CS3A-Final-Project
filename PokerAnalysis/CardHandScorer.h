//
// Created by P. Lwin on 11/13/2022.
//

#ifndef SFML_TEMPLATE_CARDHANDSCORER_H
#define SFML_TEMPLATE_CARDHANDSCORER_H
#include "CardHand.h"

//this also checks the hand and calculate the score
//and store in vector

class CardHandScorer : public CardHand {
private:
    static bool isInArray(const int arr[], const int numUsed, const int rank);
public:
    bool isRoyalFlush(std::vector<Card> temp);
    bool isStraightFlush(std::vector<Card> temp);
    bool isFourOfAKind(std::vector<Card> temp);
    bool isFullHouse(std::vector<Card> temp);
    bool isFlush(std::vector<Card> temp);
    bool isStraight(std::vector<Card> temp);
    bool isThreeOfAKind(std::vector<Card> temp);
    bool isTwoPair(std::vector<Card> temp);
    bool isOnePair(std::vector<Card> temp);
    bool isHighCard(std::vector<Card> temp);
};
#endif //SFML_TEMPLATE_CARDHANDSCORER_H
