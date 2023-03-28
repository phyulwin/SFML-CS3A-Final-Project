//
// Created by P. Lwin on 10/19/2022.
//

#include "TopahatGuy.h"
TophatGuy::TophatGuy() {
    //set constant sizes
    top.setSize(TophatGuy::HAT_TOP_SIZE);
    brim.setSize(TophatGuy::HAT_BRIM_SIZE);
    face.setRadius(TophatGuy::FACE_SIZE);

    triangle.setRadius(TophatGuy::TRIANGLE_SIZE);
    triangle.setPointCount(3);
    triangle.setRotation(180.f);

    //position other objects with relation to face
    face.setPosition(TophatGuy::FACE_POS);
    top.setPosition(TophatGuy::TOP_POS);
    brim.setPosition(TophatGuy::BRIM_POS);
    triangle.setPosition(TophatGuy::BEARD_POS);
}

void TophatGuy::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    states.transform = face.getTransform();
    window.draw(face);
    window.draw(top,states);
    window.draw(brim, states);
    window.draw(triangle, states);
}

//functions to change the position of tophatguy
void TophatGuy::setPosition(sf::Vector2f pos) {
    //this is the function that is called from main
    sf::Transformable::setPosition(pos);
    face.setPosition(pos);
}
void TophatGuy::setPosition(float x, float y) {
    setPosition(x, y);
}
void TophatGuy::setPosition() {
    float x = 0, y = 0;
    std::cout << "Enter x value: "; std::cin >> x;
    std::cout << "Enter y value: "; std::cin >> y;
    sf::Vector2f pos = {x, y};
    setPosition(pos);
}

//change color of TophatGuy object
void TophatGuy::setHatColor(const sf::Color &color) {
    TophatGuy::top.setFillColor(color);
    TophatGuy::brim.setFillColor(color);
}
void TophatGuy::setFaceColor(const sf::Color &color) {
    TophatGuy::face.setFillColor(color);
}
void TophatGuy::setBeardColor(const sf::Color &color) {
    TophatGuy::triangle.setFillColor(color);
}