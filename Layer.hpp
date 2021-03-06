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

        void setFactor(float factor);

        float getFactor();

        void setTexture(std::vector<sf::Texture>& textures, int qtty);/*, sf::Texture& texture2);*/

        void draw(sf::RenderTarget* renderTarget, sf::Transform* t);

        void update(float deltatime);

    private:
        float _speed, _factor;
        std::vector<sf::Sprite> _sprites;
//        sf::Sprite _sprite1;
//        sf::Sprite _sprite2;
};

#endif // LAYER_HPP
