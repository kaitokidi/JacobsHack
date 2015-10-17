#include "Background.hpp"

Background::Background(sf::Vector2u targetSize) {
	_pivot = sf::Vector2f(targetSize.x/2.0,targetSize.y/2.0);
	_test.setTexture(Resources::textureTest);

    layers.push_back(Layer(30));
    layers.push_back(Layer(30));
    layers.push_back(Layer(30));

    layers[0].setFactor(0.0);
    layers[1].setFactor(0.5);
    layers[2].setFactor(1);

    layers[0].setTexture(Resources::layer0,2);
    layers[1].setTexture(Resources::layer2,2);
    layers[2].setTexture(Resources::layer1,2);

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
    for(int i = 0; i < layers.size(); ++i){
        layers[i].draw(target, &_transform);
    }
    // Draw layers here :D
}

void Background::update(float deltaTime){
    //for each layer, update layer
    for(int i = 0; i < layers.size(); ++i){
        layers[i].update(deltaTime);
    }
}

void Background::setRotation(float rotation) {
	_transform = sf::Transform::Identity;
	_transform.rotate(rotation,_pivot.x,_pivot.y);
}
