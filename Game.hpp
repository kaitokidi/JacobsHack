#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "Resources.hpp"
#include "Scene.hpp"
#include "utils.hpp"

class Game {
public:
    Game();
    ~Game();

    void start();

    void changeScene(std::string sceneName);

private:
    sf::RenderWindow _window;
    std::map<std::string, Scene*> _scenes;
    Scene* _currentScene;
    Scene* _lastScene;

    sf::Mutex _mutex;
    sf::Thread* _thread;

    void loadScenes();
    void loadScene(std::string sceneName);
};

#endif