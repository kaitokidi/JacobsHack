#ifndef __SCENERACE_HPP__
#define __SCENERACE_HPP__

#include "utils.hpp"
#include "Scene.hpp"

class Game;
class SceneRace : public Scene {
public:
	SceneRace(Game* g, sf::RenderWindow* w);
	~SceneRace();

};



#endif