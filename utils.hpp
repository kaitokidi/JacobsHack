#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#define FRAMERATE 60

#define SCENEPATH "Resources/Scenes/"
#define SCENEEXTENSION ".scene"
#define SCENEEXTENSIONSIZE 6
#define TEXTURETPATH "Resources/Textures/"
#define TEXTUREDESCRIPTIONEXTENSION ".description"
#define SHADERPATH "Resources/Shaders/"
#define DATAPATH "Resources/Data/"


#include <map>
#include <list>
#include <string>
#include <dirent.h> // read directory
#include <iostream>
#include <fstream>
#include <sstream>
#include <cfloat>
#include <queue> // priority queue
#include <functional> // priority queue stuff

#include "SoundManager.hpp"

#include "GUI/Label.hpp"
#include "GUI/Frame.hpp"
#include "GUI/Layout.hpp"
#include "GUI/Widget.hpp"
#include "GUI/Button.hpp"
#include "GUI/VLayout.hpp"
#include "GUI/Container.hpp"
#include "GUI/ImgButton.hpp"
#include "GUI/TextButton.hpp"
#include "GUI/ImgTextButton.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//movement dir { down, left, right, up , none };
const int mx[5] = {0,  -1,     1,       0,   0   };
const int my[5] = {1,    0,     0,   -1,   0   };

const float TO_RADIANS = (1 / 180.0f) * (float ) M_PI;
const float TO_DEGREES = (1 / (float ) M_PI) * 180;
// Scene Status
namespace status{
    enum gameStatus {running, onMenu};
}


bool isInt(std::string s);

int myStoi(std::string s);

bool myStob(std::string s);

float difference(float a, float b);

float getAngle(const sf::Vector2f &orig,const sf::Vector2f &des);

float getModule(const sf::Vector2f &orig, const sf::Vector2f &des);

bool isCollisioning(sf::Vector2f point1, float radius1, sf::Vector2f point2, float radius2);

sf::Vector2f getRelativeCenter(sf::Vector2f origen, sf::IntRect boundOr, sf::IntRect boundDest);

#endif
