//
// Created by P. Lwin on 11/13/2022.
//

//calculates the output of poker score
#ifndef SFML_TEMPLATE_CALCULATEOUTPUT_H
#define SFML_TEMPLATE_CALCULATEOUTPUT_H
#include "PokerScore.h"

class CalculateOutput: public PokerScore {
private:
public:
    static double calculatePercentage(int totalCount, double runTime);
    static std::vector<double> runProgram();
};

#endif //SFML_TEMPLATE_CALCULATEOUTPUT_H
