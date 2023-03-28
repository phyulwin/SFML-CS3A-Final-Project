//
// Created by P. Lwin on 11/13/2022.
//
#ifndef SFML_TEMPLATE_CARDHAND_H
#define SFML_TEMPLATE_CARDHAND_H
#include "deck_class.h"

//creates a deck object
class CardHand: public Deck {
private:
    std::vector<Card> playerHand; //a vector to store all the cards in a player’s hand
    std::vector<Card> sortedPlayerHand;
public:
    const int TOTAL_CARDS = 5;
    //getter functions
    std::vector<Card> getPlayerHand() const;
    std::vector<Card> getSortedPlayerHand();

    void addCard();
    void sortCardHand();

    void printCardHand();
    void printSortedCardHand();

    void copyCardHandVectors(); //copy one vector to another
    CardHand(); //default constructor
};
#endif //SFML_TEMPLATE_CARDHAND_H
