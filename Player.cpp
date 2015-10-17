#include "Player.hpp"

Player::Player() {
	setTexture(Resources::penguin);
	setScale(sf::Vector2f(0.0723589,0.0723589));
	setPosition(30,30);
	_bounds = sf::IntRect(0,0,50,20);
}

Player::~Player(){

}

void Player::update(float deltatime){
    _velocity += _acceleration * deltatime;
}

bool Player::jumping() const{
    return _jumping;
}

void Player::setJumping(bool jumping){
    _jumping = jumping;
}

sf::Vector2f Player::velocity() const{
    return _velocity;
}

void Player::setVelocity(const sf::Vector2f &velocity){
    _velocity = velocity;
}

sf::Vector2f Player::acceleration() const{
    return _acceleration;
}

void Player::setAcceleration(const sf::Vector2f &acceleration){
    _acceleration = acceleration;
}
float Player::mass() const
{
    return _mass;
}

void Player::setMass(float mass)
{
    _mass = mass;
}


sf::IntRect Player::getMGlobalBounds() {
	return sf::IntRect(getPosition().x + _bounds.left, getPosition().y + _bounds.top, _bounds.width, _bounds.height);
}
    

sf::IntRect Player::getMBounds() {
	return _bounds;
}

