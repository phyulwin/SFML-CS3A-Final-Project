//
// Created by P. Lwin on 11/13/2022.
//
#include "CardHandScorer.h"
bool CardHandScorer::isRoyalFlush(std::vector<Card> temp) {
    if(isStraightFlush(temp) && temp[0].getRank() == ACE && temp[TOTAL_CARDS-1].getRank() == KING) {
        return true;
    }
    return false;
}

bool CardHandScorer::isStraightFlush(std::vector<Card> temp) {
    if(isStraight(temp) && isFlush(temp)) {
        return true;
    }
    return false;
}

bool CardHandScorer::isFourOfAKind(std::vector<Card> temp) {
    int rankCount = 0;
    for(int i=0; i<TOTAL_CARDS; i++) {
        ranks tempRank = temp[i].getRank();
        for(int j=i+1; j<TOTAL_CARDS; j++) {
            if(temp[j].getRank() == tempRank) {
                rankCount++;
            }
        }
        if(rankCount >= 4-1) {
            return true;
        }
        rankCount = 0; //reinitialize rankCount for a different card rank
    }
    return false;
}

bool CardHandScorer::isFullHouse(std::vector<Card> temp) {
    if(isThreeOfAKind(temp) && isOnePair(temp)) {
        return true;
    }
    return false;
}

bool CardHandScorer::isFlush(std::vector<Card> temp) {
    suits tempSuit = temp[0].getSuit();
    for(int i=0; i<TOTAL_CARDS; i++) {
        if(temp[i].getSuit() != tempSuit) {
            return false;
        }
    }
    return true;
}

bool CardHandScorer::isStraight(std::vector<Card> temp) {
    int consecutiveCount = 0;
    for(int i = 0; i < (temp.size()-1); i++) {
        if(temp[i].getRank()+1 == temp[i+1].getRank()) {
            consecutiveCount++;
        }
    }
    if(consecutiveCount == 4) {
        return true;
    }
    return false;
}

bool CardHandScorer::isThreeOfAKind(std::vector<Card> temp) {
    int rankCount = 0;
    for(int i=0; i<TOTAL_CARDS; i++) {
        ranks tempRank = temp[i].getRank();
        for(int j=i+1; j<TOTAL_CARDS; j++) {
            if(temp[j].getRank() == tempRank) {
                rankCount++;
            }
        }
        if(rankCount >= 3-1) {
            return true;
        }
        rankCount = 0; //reinitialize rankCount for a different card rank
    }
    return false;
}

bool CardHandScorer::isTwoPair(std::vector<Card> temp) {
    //check if there are at least two different ranks in the cards
    int totalRanks[TOTAL_CARDS];
    totalRanks[0] = temp[0].getRank();
    int numUsed = 1; //number of ranks in the array
    for(int i=0; i<TOTAL_CARDS; i++) {
        //check if the rank is already in the array
        if(!isInArray(totalRanks, numUsed, temp[i].getRank())) {
            //if not append
            totalRanks[numUsed] = temp[i].getRank();
            numUsed++;
        }
    }
    //return true of numUsed is either 2 or 3, else return false
    if(numUsed == 3) {
        return true;
    }
    return false;
}
bool CardHandScorer::isInArray(const int arr[], const int numUsed, const int rank) {
    for(int i=0; i<numUsed; i++) {
        if(arr[i] == rank) {
            return true;
        }
    }
    return false;
}
bool CardHandScorer::isOnePair(std::vector<Card> temp) {
    for(int i=0; i<TOTAL_CARDS; i++) {
        for(int j=i+1; j<TOTAL_CARDS; j++) {
            if(temp[i].getRank() == temp[j].getRank()) {
                return true;
            }
        }
    }
    return false;
}

bool CardHandScorer::isHighCard(std::vector<Card> temp) {
    return true; //since there is always one high card
}
