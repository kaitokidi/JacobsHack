#include "Background.hpp"

Background::Background(sf::Vector2u targetSize) {
	_pivot = sf::Vector2f(targetSize.x/2.0,targetSize.y/2.0);
	_test.setTexture(Resources::textureTest);
}

Background::~Background() {}

void Background::draw(sf::RenderTarget* target) {
	//Draw some thiings
	target->draw(_test,_transform);
	// Draw layers here :D
}

void Background::setRotation(float rotation) {
	_transform = sf::Transform::Identity;
	_transform.rotate(rotation,_pivot.x,_pivot.y);
}