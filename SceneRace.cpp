#include "SceneRace.hpp"
#include "Game.hpp"

SceneRace::SceneRace(Game* g, sf::RenderWindow* w) : Scene(g,w) {
	sf::Vector2u targetResolution(1920,1080);
	_background = new Background(targetResolution);
	initView(sf::Vector2i(targetResolution));
	_rect.setSize(sf::Vector2f(targetResolution.x, targetResolution.y/4.0));
	_rect.setPosition(sf::Vector2f(0,targetResolution.y*3.0/4.0));
	_rect.setFillColor(sf::Color::Yellow);

	_groundBounds = sf::IntRect(0,targetResolution.y*3.0/4.0,targetResolution.x, targetResolution.y/4.0);
}

SceneRace::~SceneRace() {
	delete _background;
}

void SceneRace::processInput() {
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {_window->close(); exit(0);}
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            _window->close(); exit(0);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            setRotation(_rotation+1);
        }
    }
}


void SceneRace::update(float ) {

}
	
void SceneRace::render(sf::RenderTarget* target) {
	_background->draw(target);

	target->draw(_rect);
}


void SceneRace::setRotation(float rotation) {
	_rotation = rotation;
	_background->setRotation(_rotation);
    _view.setRotation(_rotation);
}