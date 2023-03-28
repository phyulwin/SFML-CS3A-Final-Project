//
// Created by P. Lwin on 10/27/2022.
//

#include "card_class.h"
//constructors
Card::Card(std::string suit, std::string value) {

}

Card::Card(suits suit, ranks rank) : suit(suit), rank(rank) {

}
//default constructor
Card::Card() : Card(HEARTS, ACE) {

}

//other member functions
suits Card::getSuit() {
    return this->suit;
}

ranks Card::getRank() {
    return this->rank;
}

std::string Card::getSuit() const {
    switch(suit)
    {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
    }
}

std::string Card::getRank() const {
    std::string ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six",
                           "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    for(int i=0; i<RANK_COUNT; i++) {
        if(i == rank) {
            return ranks[i];
        }
    }
}

void Card::setSuit(const suits suit) {
    Card::suit = suit;
}

void Card::setRank(const ranks value) {
    Card::rank = value;
}
void Card::setSuit(int suitValue) {
    suitValue += 1;
    switch(suitValue) {
        case 1: setSuit(suits::HEARTS); break;
        case 2: setSuit(suits::DIAMONDS); break;
        case 3: setSuit(suits::CLUBS); break;
        case 4: setSuit(suits::SPADES); break;
    }
}
void Card::setRank(int rankValue) {
    rankValue += 1;
    switch(rankValue) {
        case 1: setRank(ranks::ACE); break;
        case 2: setRank(ranks::TWO); break;
        case 3: setRank(ranks::THREE); break;
        case 4: setRank(ranks::FOUR); break;
        case 5: setRank(ranks::FIVE); break;
        case 6: setRank(ranks::SIX); break;
        case 7: setRank(ranks::SEVEN); break;
        case 8: setRank(ranks::EIGHT); break;
        case 9: setRank(ranks::NINE); break;
        case 10: setRank(ranks::TEN); break;
        case 11: setRank(ranks::JACK); break;
        case 12: setRank(ranks::QUEEN); break;
        case 13: setRank(ranks::KING); break;
    }
}

//operator functions
std::ostream& operator<<(std::ostream& out, const Card& card) {
    return (out << card.getRank() << " of " << card.getSuit());
}

//vector operator overload for cards
bool operator<(const Card& lhs, const Card& rhs) {
    //compare the ranks of two cards
    return(lhs.rank < rhs.rank);
}