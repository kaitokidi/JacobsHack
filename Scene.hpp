#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include "utils.hpp"

class Game;

class Scene {
friend class Game;
public:
    Scene(Game* g, sf::RenderWindow* w);
    virtual ~Scene();

    virtual void init();
    void run();
    void killScene();

    sf::View* getPtrView();
    std::string getSceneName();
protected:
    Game* _game;
    sf::RenderWindow* _window;
    sf::View _view;

    virtual void processInput();
    virtual void update(float deltaTime);
    void render();
    virtual void render(sf::RenderTarget* target);
    void initView(sf::Vector2i windowSize);
    virtual void changeScene(std::string nextScene);

    virtual void display();

private: 
    bool _killed;
    std::string _nextSceneName;

};

#endif
