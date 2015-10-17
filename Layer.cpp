#include "Layer.hpp"

Layer::Layer()
{

}

void Layer::setSpeed(float speed){
    _speed = speed;
}

float Layer::getSpeed(){
    return _speed;
}

 void Layer::setTexture(sf::Texture& texture1, sf::Texture& texture2){
    _sprite1.setTexture(texture1);
    _sprite2.setTexture(texture2);
 }

 void Layer::draw(sf::RenderTarget* renderTarget, sf::Transform* t){
     renderTarget->draw(_sprite1,*t);
     renderTarget->draw(_sprite2,*t);
 }
