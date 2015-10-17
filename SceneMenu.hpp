#ifndef __SCENEMENU_HPP__
#define __SCENEMENU_HPP__

#include "utils.hpp"
#include "Scene.hpp"

class Game;
class SceneMenu : public Scene  {
public:
	SceneMenu(Game* g, sf::RenderWindow* w);
	~SceneMenu();

};



#endif