#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "utils.hpp"
#include "Resources.hpp"

class Player : public sf::Sprite{

public:
    Player();
    ~Player();

    void update(float deltatime);
    bool jumping() const;
    void setJumping(bool jumping);

    float mass() const;
    void setMass(float mass);
    sf::Vector2f velocity() const;
    sf::Vector2f acceleration() const;
    void setTexture(const sf::Texture &texture);
    void setVelocity(const sf::Vector2f &velocity);
    void setAcceleration(const sf::Vector2f &acceleration);

    sf::IntRect getMGlobalBounds();
    sf::FloatRect getMBounds();

    sf::Vector2f move(float deltaTime);


private:
    float _mass;
    bool _jumping;
    sf::Vector2f _velocity;
    sf::Vector2f _acceleration;
    sf::Vector2f _lastPosition;
    sf::FloatRect _bounds;
};

#endif // PLAYER_HPP
