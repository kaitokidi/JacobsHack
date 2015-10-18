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


void Layer::setTexture(std::vector<sf::Texture>& textures, int qtty ){
    for(int i = 0; i < qtty; ++i){
        sf::Sprite s;
        s.setTexture(textures[i%textures.size()]);
        _sprites.push_back(s);
    }
    for(int i = 0; i < _sprites.size(); ++i){
        _sprites[i].setPosition(sf::Vector2f(_sprites[i].getGlobalBounds().width*(-i+1),0));
    }
}

void Layer::update(float deltatime){
    float movement;
    movement = _speed*_factor*deltatime;
    for(int i = 0; i < _sprites.size(); ++i){
        _sprites[i].move(movement,0);
    }
    if(_speed < 0){
        for(int i = 0; i < _sprites.size(); ++i){
            if(_sprites[i].getPosition().x <= -1*(_sprites[i].getGlobalBounds().width)){
                _sprites[i].setPosition(sf::Vector2f((_sprites[i].getGlobalBounds().width)*float((_sprites.size()-1)),0));
            }
        }
    }
    else if (_speed > 0){
        for(int i = 0; i < _sprites.size(); ++i){
            if(_sprites[i].getPosition().x >= (_sprites[i].getGlobalBounds().width)){
                _sprites[i].setPosition(sf::Vector2f(-1.0*(_sprites[i].getGlobalBounds().width)*(float(_sprites.size()-i)),0));
            }
        }
    }
}

 void Layer::draw(sf::RenderTarget* renderTarget, sf::Transform* t){
     for(int i = 0; i < _sprites.size(); ++i){
         renderTarget->draw(_sprites[i], *t);
     }
 }
