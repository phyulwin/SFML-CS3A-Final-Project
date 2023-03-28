//
// Created by P. Lwin on 11/13/2022.
//

#include "PokerScore.h"
PokerScore::PokerScore() {
    if(!scores.empty()) {
        for(int i=0; i<scoreCount; i++) {
            scores.pop_back(); //clear all the scores for new pokerScore object
        }
    }
    scoreCount = 0;
}

void PokerScore::getScores(Scores score) {
//    std::cout << "added " << getScoreType(score) << std::endl;
    scores.push_back(score);
    scoreCount++;
}

void PokerScore::initializeScores() {
    royal_flush=0, straight_flush=0, four_of_a_kind=0, full_house=0,
    flush=0, straight=0, three_of_a_kind=0, two_pair=0, one_pair=0, high_card=0;
}

int PokerScore::size() {
    //return vector size
    return scoreCount;
}

PokerScore PokerScore::scorePokerHand(CardHand playerCards) {
    initializeScores();
    //sort the cards then calculate possible scores
    std::vector<Card> temp = playerCards.getSortedPlayerHand();
    PokerScore pokerScores;
    if(isRoyalFlush(temp)) {
        pokerScores.getScores(ROYAL_FLUSH); royal_flush++;
    }
    if(isStraightFlush(temp)) {
        pokerScores.getScores(STRAIGHT_FLUSH); straight_flush++;
    }
    if(isFourOfAKind(temp)) {
        pokerScores.getScores(FOUR_OF_A_KIND); four_of_a_kind++;
    }
    if(isFullHouse(temp)) {
        pokerScores.getScores(FULL_HOUSE); full_house++;
    }
    if(isFlush(temp)) {
        pokerScores.getScores(FLUSH); flush++;
    }
    if(isStraight(temp)) {
        pokerScores.getScores(STRAIGHT); straight++;
    }
    if(isThreeOfAKind(temp)) {
        pokerScores.getScores(THREE_OK_A_KIND); three_of_a_kind++;
    }
    if(isTwoPair(temp)) {
        pokerScores.getScores(TWO_PAIR); two_pair++;
    }
    if(isOnePair(temp)) {
        pokerScores.getScores(ONE_PAIR); one_pair++;
    }
    if(isHighCard(temp)) {
        pokerScores.getScores(HIGH_CARD); high_card++;
    }
    return pokerScores; //must return a pokerscore object
}

std::string PokerScore::getScoreType(Scores score) {
    switch(score) {
        case 0: return "ROYAL FLUSH";
        case 1: return "STRAIGHT FLUSH";
        case 2: return "FOUR OF A KIND";
        case 3: return "FULL HOUSE";
        case 4: return "FLUSH";
        case 5: return "STRAIGHT";
        case 6: return "THREE OF A KIND";
        case 7: return "TWO PAIR";
        case 8: return "ONE PAIR";
        case 9: return "HIGH_CARD";
        default: break;
    }
}

int PokerScore::royalFlushCount() const {
    return royal_flush;
}

int PokerScore::straightFlushCount() const {
    return straight_flush;
}

int PokerScore::fourOfAKindCount() const {
    return four_of_a_kind;
}

int PokerScore::fullHouseCount() const {
    return full_house;
}

int PokerScore::flushCount() const {
    return flush;
}

int PokerScore::straightCount() const {
    return straight;
}

int PokerScore::threeOfAKindCount() const {
    return three_of_a_kind;
}

int PokerScore::twoPairCount() const {
    return two_pair;
}

int PokerScore::onePairCount() const {
    return one_pair;
}

int PokerScore::highCardCount() const {
    return high_card;
}
