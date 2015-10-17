#include "Frame.hpp"

Frame::Frame(sf::RenderWindow& window) : Container(nullptr), _window(window) {}

Frame::~Frame() {}

void Frame::draw() {
    _window.draw(*this);
}

void Frame::processEvents() {
    sf::Vector2f parent_pos(0,0);
    processEvents(parent_pos);
}

bool Frame::processEvent(const sf::Event& event) {
    sf::Vector2f parent_pos(0,0);
    return processEvent(event,parent_pos);
}


sf::Vector2f Frame::getSize()const {
    sf::Vector2u size = _window.getSize();
    return sf::Vector2f(size.x,size.y);
}

bool Frame::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos) {

    bool res = false;
    if(not res)
        res = Container::processEvent(event,parent_pos);
    return res;
}

void Frame::processEvents(const sf::Vector2f& parent_pos) {

    Container::processEvents(parent_pos);

    sf::Event event;
    while(_window.pollEvent(event))
        Container::processEvent(event,parent_pos);
}
