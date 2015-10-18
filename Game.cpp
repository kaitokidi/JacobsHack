#include "Game.hpp"
#include "Portada.hpp"
Game::Game() : _window(sf::VideoMode::getDesktopMode(),"TOPKeK", sf::Style::Fullscreen) {

    Portada portada;
    portada.display(&_window, "Resources/Textures/portada.png");
    portada.display(&_window, "Resources/Textures/BEST.png");
    _window.setFramerateLimit(FRAMERATE);
    Resources::load();
    _currentScene = nullptr;
    _lastScene = nullptr;
    SoundManager::load();
   
    //SoundManager::setLoop(true, "overWorld");
}

Game::~Game() {
    for (auto it = _scenes.begin(); it != _scenes.end(); ++it) {
        delete it->second;
    }
}

void Game::start() {
    loadScenes();

    _currentScene = (*_scenes.find("Menu")).second;

    while (_currentScene != nullptr) {
        _currentScene->run();
    }

    exit(0);
}


void Game::changeScene(std::string nextSceneName, int nPlayers) { // This will be called by any scene when something trigers to change to anothe scene
    std::string sceneName = nextSceneName;
    std::cout << "You want to change to: " << sceneName << std::endl;
    if (_currentScene != nullptr) {
        _lastScene = _currentScene;
        _currentScene->killScene();
    }
    auto it = _scenes.find(sceneName);
    if (it == _scenes.end()) {
        std::cout << "The selected scene does not exist: " << sceneName << std::endl;
        exit(EXIT_FAILURE);
    }
    Scene* aux = (*it).second;
    
    std::cout << "Changing to scene " << sceneName << std::endl;

    _currentScene = aux;
    if (nextSceneName == "Jump") _currentScene->init(nPlayers);   
    else _currentScene->init();    
}


void Game::loadScenes() {
    _scenes.insert(std::make_pair(
            "Menu",
            new SceneMenu(this,&_window)));
    _scenes.insert(std::make_pair(
            "Jump",
            new SceneRace(this,&_window)));
}
