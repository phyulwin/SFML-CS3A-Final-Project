//
// Created by P. Lwin on 11/14/2022.
//
#include "calculateOutput.h"
double CalculateOutput::calculatePercentage(int totalCount, double runTime) {
    //calculate possibility of getting each card hand score
    return (runTime / totalCount);
}

std::vector<double> CalculateOutput::runProgram() {
    std::vector<double> scoresPercentage;
    int royal_flush=0, straight_flush=0, four_of_a_kind=0, full_house=0,
            flush=0, straight=0, three_of_a_kind=0, two_pair=0, one_pair=0, high_card=0;

    int totalRunCount = 0;
    //create a new card hand and pokerscore object
    CardHand newCardHand;
    PokerScore pokerScore;
    do {
        newCardHand.addCard();
        pokerScore.scorePokerHand(newCardHand);

        //add the score count for this card hand
        royal_flush += pokerScore.royalFlushCount();
        straight_flush += pokerScore.straightFlushCount();
        four_of_a_kind += pokerScore.fourOfAKindCount();
        full_house += pokerScore.fullHouseCount();
        flush += pokerScore.flushCount();
        straight += pokerScore.straightCount();
        three_of_a_kind += pokerScore.threeOfAKindCount();
        two_pair += pokerScore.twoPairCount();
        one_pair += pokerScore.onePairCount();
        high_card += pokerScore.highCardCount();
        //count the total run time
        totalRunCount++;
    } while(straight_flush < 1);

    //print out score counts
    std::cout << "ROYAL_FLUSH: " << royal_flush << std::endl << std::endl;
    std::cout << "STRAIGHT_FLUSH: " << straight_flush << std::endl << std::endl;
    std::cout << "FOUR_OF_A_KIND: " << four_of_a_kind << std::endl << std::endl;
    std::cout << "FULL_HOUSE: " << full_house << std::endl << std::endl;
    std::cout << "FLUSH: " << flush << std::endl << std::endl;
    std::cout << "STRAIGHT: " << straight << std::endl << std::endl;
    std::cout << "THREE_OF_A_KIND: " << three_of_a_kind << std::endl << std::endl;
    std::cout << "TWO_PAIR: " << two_pair << std::endl << std::endl;
    std::cout << "ONE_PAIR: " << one_pair << std::endl << std::endl;
    std::cout << "HIGH_CARD: " << high_card << std::endl << std::endl;

    //calculate the odds of getting each card hand given total run time
    double royalFlushP = calculatePercentage(totalRunCount, royal_flush);
    double straightFlushP = calculatePercentage(totalRunCount, straight_flush);
    double fourOfAKindP = calculatePercentage(totalRunCount, four_of_a_kind);
    double fullHouseP = calculatePercentage(totalRunCount, full_house);
    double flushP = calculatePercentage(totalRunCount, flush);
    double straightP = calculatePercentage(totalRunCount, straight);
    double threeOfAKindP = calculatePercentage(totalRunCount, three_of_a_kind);
    double twoPairP = calculatePercentage(totalRunCount, two_pair);
    double onePairP = calculatePercentage(totalRunCount, one_pair);
    double highCardP = calculatePercentage(totalRunCount, high_card);

    //append to vector and return
    scoresPercentage.push_back(royalFlushP);
    scoresPercentage.push_back(straightFlushP);
    scoresPercentage.push_back(fourOfAKindP);
    scoresPercentage.push_back(fullHouseP);
    scoresPercentage.push_back(flushP);
    scoresPercentage.push_back(straightP);
    scoresPercentage.push_back(threeOfAKindP);
    scoresPercentage.push_back(twoPairP);
    scoresPercentage.push_back(onePairP);
    scoresPercentage.push_back(highCardP);
    std::cout << "Running " << totalRunCount << " times." << std::endl;
    return scoresPercentage;
}