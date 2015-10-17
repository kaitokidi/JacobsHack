#ifndef LAYER_HPP
#define LAYER_HPP

#include "utils.hpp"

class Layer
{
    public:
        Layer();

        void setSpeed(float speed);

        float getSpeed();

        void setTexture(sf::Texture& texture1, sf::Texture& texture2);
        //states
        void draw(sf::RenderTarget* renderTarget, sf::Transform* t);

        void update();

    private:
        float _speed;
        sf::Sprite _sprite1;
        sf::Sprite _sprite2;
};

#endif // LAYER_HPP
