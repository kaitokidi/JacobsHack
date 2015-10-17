#ifndef __SCENERACE_HPP__
#define __SCENERACE_HPP__

#include "utils.hpp"
#include "Scene.hpp"
#include "Background.hpp"

class Game;
class SceneRace : public Scene {
public:
	SceneRace(Game* g, sf::RenderWindow* w);
	~SceneRace();

	void update(float deltaTime);
	void render(sf::RenderTarget* target);
	void processInput();
private:
	Background* _background;
	// std::vector<Player> _players;
	// int _nPlayers;

	sf::RectangleShape _rect;
	sf::IntRect _groundBounds;
	float _rotation;

	void setRotation(float rotation);
};



#endif