#ifndef __BACKGROUND_HPP__
#define __BACKGROUND_HPP__ 

#include "utils.hpp"
#include "Layer.hpp"
#include "Resources.hpp"

class Background {
public:
	Background(sf::Vector2u targetSize);
	~Background();

    void setSpeed(float speed);
    void update(float deltaTime);
    void setRotation(float rotation);
	void draw(sf::RenderTarget* target);

private:

    sf::Sprite _test;
    sf::Vector2f _pivot;
	sf::Transform _transform;
    std::vector<Layer> layers;

};



#endif
