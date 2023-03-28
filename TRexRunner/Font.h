//
// Created by 646ca on 12/8/2022.
//

#ifndef SFML_TEMPLATE_FONT_H
#define SFML_TEMPLATE_FONT_H

#include <SFML\Graphics.hpp>
#include <map>

enum  fontsEnum {
    OPEN_SANS,
    MONOGRAM,
    LAST_FONT
};
class Fonts {
private:
    static std::map<fontsEnum, sf::Font> map;
    static void load(fontsEnum font);
    static std::string getPath(fontsEnum font); //return path of font
public:
    static sf::Font& getFont(fontsEnum font);
};
#endif //SFML_TEMPLATE_FONT_H
