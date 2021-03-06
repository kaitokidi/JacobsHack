#include "Button.hpp"
#include <iostream>
Button::FuncType Button::defaultFunc = [](const sf::Event&,Button&)->void{};

Button::Button(Widget* parent) : Widget(parent),
onClick(defaultFunc), _status(Status::None) {  }

Button::~Button() {  }

bool Button::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos) {
    bool res = false;
    if(event.type == sf::Event::MouseButtonReleased) {
        const sf::Vector2f pos = parent_pos + _position;
        const sf::Vector2f size = getSize();
        sf::FloatRect rect(pos.x, pos.y, size.x, size.y);
        if(rect.contains(event.mouseButton.x,event.mouseButton.y)) {
            onClick(event,*this);
            res = true;
        }
    } else if (event.type == sf::Event::MouseMoved) {
        const sf::Vector2f pos = parent_pos + _position;
        const sf::Vector2f size = getSize();
        sf::FloatRect rect(pos.x, pos.y, size.x, size.y);
        int old_status = _status;
        _status = Status::None;
        if(rect.contains(event.mouseMove.x,event.mouseMove.y))
            _status=Status::Hover;
        if((old_status & Status::Hover) and not (_status & Status::Hover))
            onMouseLeft();
        else if(not (old_status & Status::Hover) and (_status & Status::Hover))
            onMouseEntered();
    }
    return res;
}

void Button::onMouseEntered() {}
void Button::onMouseLeft() {}
