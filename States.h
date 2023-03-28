//
// Created by 646ca on 12/8/2022.
//

#ifndef SFML_TEMPLATE_STATES_H
#define SFML_TEMPLATE_STATES_H
#include "enumList.h"
#include <map>

class States {
private:
    std::map<statesEnum, bool> map;
    void load();
public:
    States();

    bool checkState(statesEnum state) const; //true if enum is in map; false otherwise
    void enableState(statesEnum state); //make state true in the map
    void disableState(statesEnum state); //make state false in the map
    void setState(statesEnum state, bool value);
    void toggleState(statesEnum state); //switch between true and false
};
#endif //SFML_TEMPLATE_STATES_H
