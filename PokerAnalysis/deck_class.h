//
// Created by P. Lwin on 11/13/2022.
//

#ifndef SFML_TEMPLATE_DECK_CLASS_H
#define SFML_TEMPLATE_DECK_CLASS_H

#include <cstdlib>
#include <ctime>

#include "card_class.h"

//creates a deck object for pokeranalysis
class Deck : public Card {
private:
    //creates a card object
    Card card;
    Card deck[52];// this is your final deck of cards

    const int DECK_SIZE = 52;// this is the size of your deck
    bool empty(); //returns true if deck has no cards
    int cardIndex; //marks the index of the next card in the deck
public:
    Deck();
    void refillDeck();
    void shuffle(); // puts cards in random order
    void printDeck(); //prints cards in deck
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console
    Card dealCard(); // returns the next card in the deck
    Card getCardAt(int index);// gets the Card at the given index
};
#endif //SFML_TEMPLATE_DECK_CLASS_H
