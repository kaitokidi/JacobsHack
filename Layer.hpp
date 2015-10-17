#ifndef LAYER_HPP
#define LAYER_HPP

#include "utils.hpp"

class Layer
{
    public:
        Layer();

        Layer(float speed);

        void setSpeed(float speed);

        float getSpeed();

        void setTexture(sf::Texture& texture1, sf::Texture& texture2);

        void draw(sf::RenderTarget* renderTarget, sf::Transform* t);

        void update(float deltatime);

    private:
        float _speed;
        sf::Sprite _sprite1;
        sf::Sprite _sprite2;
};

#endif // LAYER_HPP
