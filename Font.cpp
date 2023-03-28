//
// Created by 646ca on 12/8/2022.
//

#include "Font.h"

std::map<fontsEnum, sf::Font> Fonts::map;
void Fonts::load(fontsEnum font) {
    map[font].loadFromFile(getPath(font));
}

std::string Fonts::getPath(fontsEnum font) {
    switch (font) {
        case OPEN_SANS: return "Fonts/opensansboldfont.ttf";
        case MONOGRAM: return "Fonts/monogram.ttf";
        case LAST_FONT: return "";
    }
}

sf::Font &Fonts::getFont(fontsEnum font) {
    load(font);
    return map[font];
}
