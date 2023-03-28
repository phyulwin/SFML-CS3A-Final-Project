//
// Created by P. Lwin on 11/13/2022.
//

#include "deck_class.h"

bool Deck::empty() {
    if(cardIndex <= 0) {
        return true;
    }
    return false;
}

Deck::Deck() {
    cardIndex = DECK_SIZE - 1;
    refillDeck();
    shuffle();
}

void Deck::refillDeck() {
    //since the first card starts at index 0
    // load Deck with 52 cards
    for(int i=0, suitValue=0, rankValue=0; i<DECK_SIZE; i++, rankValue++) {
        if(rankValue==13) {
            suitValue+=1; rankValue=0;
        }
        Card tempCard;
        tempCard.setSuit(suitValue);
        tempCard.setRank(rankValue);
        deck[i] = tempCard;
    }
}

void Deck::shuffle() {
//    srand(time(NULL));
    // puts cards in random order
    for(int i=0; i<DECK_SIZE; i++) {
        int index = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[index];
        deck[index] = temp;
    }
    //use swap to switch two cards at random indexes
    //also use rand to choose two cards
}

void Deck::printDeck() {
    shuffle();
    for(int i=0; i<DECK_SIZE; i++) {
        std::cout << std::to_string(i+1) << ": " << deck[i] << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    // prints all the cards to the console
    return out << deck;
}
Card Deck::dealCard() {
    // returns the next card in the deck
    //subtract one card from deck
    Card temp;
    cardIndex--;
    if(empty()) {
        cardIndex = DECK_SIZE-1; //refill cards if deck is empty
        refillDeck();
        shuffle();
    }
    temp = deck[cardIndex];
    return temp;
}
Card Deck::getCardAt(int index) {
    // returns the Card at the given index
    //subtract one card from deck
    Deck::cardIndex -= 1;
    return deck[index];
}