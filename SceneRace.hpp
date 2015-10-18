#ifndef __SCENERACE_HPP__
#define __SCENERACE_HPP__

#include "utils.hpp"
#include "Scene.hpp"
#include "Background.hpp"
#include "Player.hpp"

class Game;
class SceneRace : public Scene {
public:
	SceneRace(Game* g, sf::RenderWindow* w);
	~SceneRace();

	void init(int nPlayers);
	void update(float deltaTime);
	void render(sf::RenderTarget* target);
	void processInput();
private:
	Background* _background;
	std::vector<Player> _players;
	int _nPlayers;

	sf::RectangleShape _rect;
	sf::RectangleShape _rect2;
	sf::RectangleShape _rect3;
	sf::IntRect _groundBounds;
	float _rotation;
	float _speed;

	void setRotation(float rotation);
	float SweptAABB(Player* p1, Player* p2, float& normalx, float& normaly);
};



#endif