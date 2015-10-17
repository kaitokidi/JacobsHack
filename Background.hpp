#ifndef __BACKGROUND_HPP__
#define __BACKGROUND_HPP__ 

#include "utils.hpp"
#include "Resources.hpp"

class Background {
public:
	Background(sf::Vector2u targetSize);
	~Background();

	void draw(sf::RenderTarget* target);

	void setRotation(float rotation);
private:
    sf::Sprite _test;

	sf::Transform _transform;
	sf::Vector2f _pivot;

};



#endif