#include "Layer.hpp"

Layer::Layer() {
    _speed = 0;
}

Layer::Layer(float speed) {
    _speed = speed;
}

void Layer::setSpeed(float speed){
    _speed = speed;
}

float Layer::getSpeed(){
    return _speed;
}

void Layer::setFactor(float factor){
    _factor = factor;
}

float Layer::getFactor(){
    return _factor;
}


void Layer::setTexture(sf::Texture& texture1, sf::Texture& texture2){
    _sprite1.setTexture(texture1);
    _sprite2.setTexture(texture2);
    _sprite1.setPosition(sf::Vector2f(0,0));
    _sprite2.setPosition(sf::Vector2f(_sprite1.getGlobalBounds().width,0));
}

void Layer::update(float deltatime){
    float movement;
    movement = _speed*_factor*deltatime;
    _sprite1.move(movement,0);
    _sprite2.move(movement,0);
    if(_sprite1.getPosition().x < -1*(_sprite1.getGlobalBounds().width)){
        _sprite1.setPosition(sf::Vector2f(_sprite1.getGlobalBounds().width,0));
    }
    else if(_sprite2.getPosition().x < -1*(_sprite2.getGlobalBounds().width)){
       _sprite2.setPosition(sf::Vector2f(_sprite1.getGlobalBounds().width,0));
    }
}

 void Layer::draw(sf::RenderTarget* renderTarget, sf::Transform* t){
     renderTarget->draw(_sprite1,*t);
     renderTarget->draw(_sprite2,*t);
 }
