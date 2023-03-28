//
// Created by P. Lwin on 11/13/2022.
//

#include "CardHand_Cards.h"

CardHand_Cards::CardHand_Cards() {
    //default constructor
    appendCards();
    arrangeCards();
    scoresPercentage = CalculateOutput::runProgram();
    textDisplayForScores();
}

void CardHand_Cards::appendCards() {
    appendRoyalFlushCards();
    appendStraightFlushCards();
    appendFourOfAKindCards();
    appendFullHouseCards();
    appendFlushCards();
    appendStraightCards();
    appendThreeOfAKindCards();
    appendTwoPairCards();
    appendOnePairCards();
    appendHighCardCards();
}

void CardHand_Cards::arrangeCards() {
    const int LEFT_ALIGN = 50;
    const int TOP_ALIGN = 10;
    setCardPositions(royalFlushCards, {LEFT_ALIGN, TOP_ALIGN}); royalFlushText.setPosition({LEFT_ALIGN, 110});
    setCardPositions(straightFlushCards, {LEFT_ALIGN, TOP_ALIGN+140}); straightFlushText.setPosition({LEFT_ALIGN, 250});
    setCardPositions(fourOfAKindCards, {LEFT_ALIGN, TOP_ALIGN+280}); fourOfAKindText.setPosition({LEFT_ALIGN, 390});
    setCardPositions(fullHouseCards, {LEFT_ALIGN, TOP_ALIGN+420}); fullHouseText.setPosition({LEFT_ALIGN, 530});
    setCardPositions(flushCards, {LEFT_ALIGN, TOP_ALIGN+560}); flushText.setPosition({LEFT_ALIGN, 670});
    const int RIGHT_ALIGN = 670;
    setCardPositions(straightCards, {RIGHT_ALIGN, TOP_ALIGN}); straightText.setPosition({RIGHT_ALIGN, 110});
    setCardPositions(threeOfAKindCards, {RIGHT_ALIGN, TOP_ALIGN+140}); threeOfAKindText.setPosition({RIGHT_ALIGN, 250});
    setCardPositions(twoPairCards, {RIGHT_ALIGN, TOP_ALIGN+280}); twoPairText.setPosition({RIGHT_ALIGN, 390});
    setCardPositions(onePairCards, {RIGHT_ALIGN, TOP_ALIGN+420}); onePairText.setPosition({RIGHT_ALIGN, 530});
    setCardPositions(highCardCards, {RIGHT_ALIGN, TOP_ALIGN+560}); highCardText.setPosition({RIGHT_ALIGN, 670});
}

void CardHand_Cards::appendRoyalFlushCards() {
    //cards for royal flush
    CardSMFL card1(HEARTS, KING), card2(HEARTS, QUEEN), card3(HEARTS, JACK), card4(HEARTS, TEN), card5(HEARTS, ACE);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        royalFlushCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendStraightFlushCards() {
    //cards for straight flush
    CardSMFL card1(DIAMONDS, ACE), card2(DIAMONDS, TWO), card3(DIAMONDS, THREE), card4(DIAMONDS, FOUR), card5(DIAMONDS, FIVE);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        straightFlushCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendFourOfAKindCards() {
    //cards for four of a kind
    CardSMFL card1(HEARTS, JACK), card2(CLUBS, JACK), card3(DIAMONDS, JACK), card4(SPADES, JACK), card5(CLUBS, TEN);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        fourOfAKindCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendFullHouseCards() {
    //cards for full house
    CardSMFL card1(HEARTS, QUEEN), card2(DIAMONDS, QUEEN), card3(SPADES, QUEEN), card4(CLUBS, TEN), card5(HEARTS, TEN);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        fullHouseCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendFlushCards() {
    //cards for flush
    CardSMFL card1(DIAMONDS, ACE), card2(DIAMONDS, FOUR), card3(DIAMONDS, FIVE), card4(DIAMONDS, SEVEN), card5(DIAMONDS, NINE);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        flushCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendStraightCards() {
    //cards for straight
    CardSMFL card1(CLUBS, ACE), card2(CLUBS, TWO), card3(CLUBS, THREE), card4(CLUBS, FOUR), card5(CLUBS, FIVE);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        straightCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendThreeOfAKindCards() {
    //card for three of a kind
    CardSMFL card1(HEARTS, FOUR), card2(DIAMONDS, FOUR), card3(CLUBS, FOUR), card4(DIAMONDS, KING), card5(CLUBS, JACK);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        threeOfAKindCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendTwoPairCards() {
    //card for two pair
    CardSMFL card1(CLUBS, TWO), card2(HEARTS, TWO), card3(DIAMONDS, KING), card4(HEARTS, KING), card5(HEARTS, EIGHT);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        twoPairCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendOnePairCards() {
    //card for one pair
    CardSMFL card1(CLUBS, SEVEN), card2(DIAMONDS, EIGHT), card3(HEARTS, NINE), card4(HEARTS, QUEEN), card5(DIAMONDS, QUEEN);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        onePairCards.push_back(cards[i]);
    }
}

void CardHand_Cards::appendHighCardCards() {
    //card for high card
    CardSMFL card1(HEARTS, SIX), card2(DIAMONDS, FIVE), card3(CLUBS, NINE), card4(CLUBS, JACK), card5(HEARTS, KING);
    CardSMFL cards[] = {card1, card2, card3, card4, card5};
    for(int i=0; i<CARD_COUNT; i++) {
        highCardCards.push_back(cards[i]);
    }
}

void CardHand_Cards::setCardPositions(std::vector<CardSMFL>& cardHand, sf::Vector2f positionOfHand) const {
    //set position of cards
    float x = positionOfHand.x;
    for(int i=0; i<CARD_COUNT; i++) {
        //change the distance between each cards of the hand
        cardHand[i].setPosition({x, positionOfHand.y});
        x += 100;
    }
}

void CardHand_Cards::textDisplayForScores() {
    //text display _ set up fonts
    if(!font.loadFromFile("PokerAnalysis/font/opensansboldfont.ttf"))
        exit(10);
    //set font
    royalFlushText.setFont(font), straightFlushText.setFont(font), fourOfAKindText.setFont(font), fullHouseText.setFont(font),
            flushText.setFont(font), straightText.setFont(font), threeOfAKindText.setFont(font), twoPairText.setFont(font), onePairText.setFont(font), highCardText.setFont(font);
    //set character size
    royalFlushText.setCharacterSize(FONT_SIZE), straightFlushText.setCharacterSize(FONT_SIZE), fourOfAKindText.setCharacterSize(FONT_SIZE),
    fullHouseText.setCharacterSize(FONT_SIZE), flushText.setCharacterSize(FONT_SIZE), straightText.setCharacterSize(FONT_SIZE),
    threeOfAKindText.setCharacterSize(FONT_SIZE), twoPairText.setCharacterSize(FONT_SIZE), onePairText.setCharacterSize(FONT_SIZE), highCardText.setCharacterSize(FONT_SIZE);
    //set strings
    //string concatenation
    const std::string text0 = "ROYAL FLUSH: " + std::to_string(scoresPercentage[0]) + "%";
    const std::string text1 = "STRAIGHT FLUSH: " + std::to_string(scoresPercentage[1]) + "%";
    const std::string text2 = "FOUR OF A KIND: " + std::to_string(scoresPercentage[2]) + "%";
    const std::string text3 = "FULL HOUSE: " + std::to_string(scoresPercentage[3]) + "%";
    const std::string text4 = "FLUSH: " + std::to_string(scoresPercentage[4]) + "%";
    const std::string text5 = "STRAIGHT: " + std::to_string(scoresPercentage[5]) + "%";
    const std::string text6 = "THREE OF A KIND: " + std::to_string(scoresPercentage[6]) + "%";
    const std::string text7 = "TWO PAIR: " + std::to_string(scoresPercentage[7]) + "%";
    const std::string text8 = "ONE PAIR: " + std::to_string(scoresPercentage[8]) + "%";
    const std::string text9 = "HIGH CARD: " + std::to_string(scoresPercentage[9]) + "%";
    //
    royalFlushText.setString(text0), straightFlushText.setString(text1), fourOfAKindText.setString(text2),
    fullHouseText.setString(text3), flushText.setString(text4), straightText.setString(text5),
    threeOfAKindText.setString(text6), twoPairText.setString(text7), onePairText.setString(text8), highCardText.setString(text9);
}
