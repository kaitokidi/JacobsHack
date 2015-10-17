#include "SceneRace.hpp"
#include "Game.hpp"

SceneRace::SceneRace(Game* g, sf::RenderWindow* w) : Scene(g,w) {
	sf::Vector2u targetResolution(640,360);
	initView(sf::Vector2i(targetResolution));
	sf::Vector2u displayResolution(_view.getSize());

	_speed = 0;
	_nPlayers = 4;
	_rotation = 0;
	_players = std::vector<Player>(_nPlayers);
	_background = new Background(displayResolution);


	_rect.setSize(sf::Vector2f(displayResolution.x, displayResolution.y));
	_rect.setPosition(sf::Vector2f(-0.5*displayResolution.x,displayResolution.y*3.0/4.0));
	_rect.setFillColor(sf::Color::Yellow);
	_rect2.setSize(sf::Vector2f(displayResolution.x, displayResolution.y));
	_rect2.setPosition(sf::Vector2f(0.5*displayResolution.x,displayResolution.y*3.0/4.0));
	_rect2.setFillColor(sf::Color::Red);
	_rect3.setSize(sf::Vector2f(displayResolution.x, displayResolution.y));
	_rect3.setPosition(sf::Vector2f(1.5*displayResolution.x,displayResolution.y*3.0/4.0));
	_rect3.setFillColor(sf::Color::Blue);

	_groundBounds = sf::IntRect(0,displayResolution.y*3.0/4.0,displayResolution.x, displayResolution.y/4.0);
}

SceneRace::~SceneRace() {
	delete _background;
}

void SceneRace::init(int nPlayers) {
	_nPlayers = nPlayers;
	_rotation = 0;
}

void SceneRace::processInput() {
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {_window->close(); exit(0);}
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            _window->close(); exit(0);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
            setRotation(_rotation+1);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
            setRotation(_rotation-1);
        }
    }
}


void SceneRace::update(float deltaTime) {
	_rotation = (int)_rotation%360;
	_speed += 2*sin(_rotation*TO_RADIANS)*TO_DEGREES*deltaTime;
	_speed = std::min(50.0f, std::max(_speed,-50.0f));
	_rect.move(sf::Vector2f(_speed,0));
	_rect2.move(sf::Vector2f(_speed,0));
	_rect3.move(sf::Vector2f(_speed,0));
	if (_rect.getPosition().x  < -1.5*_view.getSize().x) _rect.move( sf::Vector2f(3*_view.getSize().x,0));
	else if(_rect.getPosition().x  > 1.5*_view.getSize().x) _rect.move( sf::Vector2f(-3*_view.getSize().x,0));
	if (_rect2.getPosition().x < -1.5*_view.getSize().x) _rect2.move(sf::Vector2f(3*_view.getSize().x,0));
	else if(_rect2.getPosition().x  > 1.5*_view.getSize().x) _rect2.move( sf::Vector2f(-3*_view.getSize().x,0));
	if (_rect3.getPosition().x < -1.5*_view.getSize().x) _rect3.move(sf::Vector2f(3*_view.getSize().x,0));
	else if(_rect3.getPosition().x  > 1.5*_view.getSize().x) _rect3.move( sf::Vector2f(-3*_view.getSize().x,0));

	for (int i = 0; i < _nPlayers; ++i) _players[i].update(deltaTime);


}
	
void SceneRace::render(sf::RenderTarget* target) {
	_background->draw(target);

	target->draw(_rect);
	target->draw(_rect2);
	target->draw(_rect3);
	for (int i = 0; i < _nPlayers; ++i) target->draw(_players[i]);
}


void SceneRace::setRotation(float rotation) {
	_rotation = rotation;
	_background->setRotation(_rotation);
    _view.setRotation(_rotation);
}