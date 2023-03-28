//
// Created by P. Lwin on 11/13/2022.
//

#ifndef SFML_TEMPLATE_POKERSCORE_H
#define SFML_TEMPLATE_POKERSCORE_H
#include "CardHandScorer.h"

//creats a pokerscore scores vector object that keeps track of the scores
class PokerScore: public CardHandScorer {
private:
    enum Scores {
        ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.
        STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking
        FOUR_OF_A_KIND, //four cards of the same ranking
        FULL_HOUSE, //three cards of the same rank along with two cards of the same rank
        FLUSH, //five cards of the same suit
        STRAIGHT, //five cards in consecutive ranking
        THREE_OK_A_KIND, //three cards of the same rank
        TWO_PAIR, //two cards of the same rank along with another two cards of the same rank
        ONE_PAIR, //two cards of the same rank
        HIGH_CARD //highest card in the player’s hand
    };
    std::vector<Scores> scores;
    int scoreCount;
    int royal_flush, straight_flush, four_of_a_kind, full_house,
            flush, straight, three_of_a_kind, two_pair, one_pair, high_card;
public:
    PokerScore();
    void getScores(Scores score);
    void initializeScores();
    std::string getScoreType(Scores score);

    int size(); //get scores vector size
    //getter functions
    int royalFlushCount() const;
    int straightFlushCount() const;
    int fourOfAKindCount() const;
    int fullHouseCount() const;
    int flushCount() const;
    int straightCount() const;
    int threeOfAKindCount() const;
    int twoPairCount() const;
    int onePairCount() const;
    int highCardCount() const;

    //calculate poker scores given player hand
    PokerScore scorePokerHand(CardHand playerCards);
};
#endif //SFML_TEMPLATE_POKERSCORE_H
