#include "Background.hpp"

Background::Background(sf::Vector2u targetSize) {
	_pivot = sf::Vector2f(targetSize.x/2.0,targetSize.y/2.0);
	_test.setTexture(Resources::textureTest);

    layers.push_back(new Layer(30));
    layers.push_back(new Layer(30));
    layers.push_back(new Layer(30));

    layers[0].setFactor(1);
    layers[1].setFactor(2);
    layers[2].setFactor(2.5);

}

Background::~Background() {}

void Background::setSpeed(float speed){
    for(int i = 0; i < layers.size(); ++i){
        layers[i].setSpeed(speed);
    }
}



void Background::draw(sf::RenderTarget* target) {
	//Draw some thiings
    target->draw(_test,_transform);
    //for each layer
    for(int i; i < layers.size(); ++i){
        layers[i].draw(target, _transform);
    }
    // Draw layers here :D
}

void Background::update(float deltaTime){
    //for each layer, update layer
    for(int i; i < layers.size(); ++i){
        layers[i].update(deltaTime);
    }
}

void Background::setRotation(float rotation) {
	_transform = sf::Transform::Identity;
	_transform.rotate(rotation,_pivot.x,_pivot.y);
}
