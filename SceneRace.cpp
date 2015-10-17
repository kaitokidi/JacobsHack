#include "SceneRace.hpp"
#include "Game.hpp"

SceneRace::SceneRace(Game* g, sf::RenderWindow* w) : Scene(g,w) {
	sf::Vector2i targetResolution(1920,1080);
	initView(targetResolution);
	_rect.setSize(sf::Vector2f(targetResolution.x, targetResolution.y/4.0));
	_rect.setPosition(sf::Vector2f(0,targetResolution.y*3.0/4.0));
	_rect.setFillColor(sf::Color::Yellow);

	_groundBounds = sf::IntRect(0,targetResolution.y*3.0/4.0,targetResolution.x, targetResolution.y/4.0);
}

SceneRace::~SceneRace() {}


void SceneRace::update(float ) {

}
	
void SceneRace::render(sf::RenderTarget* target) {
	target->draw(_rect);
}