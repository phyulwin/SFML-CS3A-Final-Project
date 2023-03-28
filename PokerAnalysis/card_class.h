//
// Created by P. Lwin on 11/13/2022.
//
#ifndef SFML_TEMPLATE_CARD_CLASS_H
#define SFML_TEMPLATE_CARD_CLASS_H

//this also creates a card object for pokeranalysis
//include libraries
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <SFML\Graphics.hpp>

//get enum data type from header files
#include "suits_struct.h"
#include "ranks_struct.h"

class Card {
private:
    suits suit;
    ranks rank;
public:
    int RANK_COUNT = 13;
    //int SUIT_COUNT = 4;
    suits getSuit();
    ranks getRank();

    std::string getSuit() const;
    std::string getRank() const;

    void setSuit(const suits suit);
    void setRank(const ranks value);

    void setSuit(int suitValue);
    void setRank(int rankValue);

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    Card(std::string suit, std::string value);
    Card(suits suit, ranks rank);
    Card();

    //compare ranks of cards
    friend bool operator<(const Card& lhs, const Card& rhs);
};

#endif //SFML_TEMPLATE_CARD_CLASS_H
