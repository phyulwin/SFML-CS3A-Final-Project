//
// Created by P. Lwin on 11/13/2022.
//
#include "CardHand.h"
CardHand::CardHand() {
    //default constructor
}

void CardHand::addCard() {
    if(!playerHand.empty()) {
        for(int i=0; i<TOTAL_CARDS; i++) {
            playerHand.pop_back();
        }
    }
    if(!sortedPlayerHand.empty()) {
        for(int i=0; i<TOTAL_CARDS; i++) {
            sortedPlayerHand.pop_back();
        }
    }
    for (int i = 0; i < TOTAL_CARDS; i++){
        playerHand.push_back(dealCard());
    }
    sortCardHand();
}

std::vector<Card> CardHand::getPlayerHand() const {
    return this->playerHand;
}

std::vector<Card> CardHand::getSortedPlayerHand() {
    this->sortCardHand();
    return this->sortedPlayerHand;
}

void CardHand::printCardHand() {
    std::cout << std::endl << std::endl;
    for(int i=0; i<TOTAL_CARDS; i++) {
        std::cout << std::to_string(i+1) << ": " << playerHand[i] << std::endl;
    }
}

void CardHand::printSortedCardHand() {
    std::cout << std::endl << std::endl;
    for(int i=0; i<TOTAL_CARDS; i++) {
        std::cout << std::to_string(i+1) << ": " << sortedPlayerHand[i] << std::endl;
    }
}

void CardHand::sortCardHand() {
    //creates a copy of the original card hand
    copyCardHandVectors();
    //using bubble sort
    for(int i=0; i<TOTAL_CARDS-1; i++) {
        for(int j=0; j<TOTAL_CARDS-1; j++) {
            if(sortedPlayerHand[j] < sortedPlayerHand[j+1]) {
                std::swap(sortedPlayerHand[j], sortedPlayerHand[j+1]);
            }
        }
    }
    //reverse the order of cards again
    std::swap(sortedPlayerHand[0], sortedPlayerHand[4]);
    std::swap(sortedPlayerHand[1], sortedPlayerHand[3]);
}

void CardHand::copyCardHandVectors() {
    //empty vector first before pushing
    if(!sortedPlayerHand.empty()) {
        for(int i=0; i<TOTAL_CARDS; i++) {
            sortedPlayerHand.pop_back();
        }
    }
    for(int i=0; i<TOTAL_CARDS; i++) {
        sortedPlayerHand.push_back(playerHand[i]);
    }
}

