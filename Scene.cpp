#include "Scene.hpp"
#include "Game.hpp"

Scene::Scene(Game* g, sf::RenderWindow* w) :
    _game(g), 
    _window(w), 
    _killed(false) {
}

Scene::~Scene(){}


void Scene::init() {

}

void Scene::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time timePerFrame = sf::seconds(1.f/FRAMERATE);

    while (_window->isOpen()) {
        processInput();
        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            update(timePerFrame.asSeconds());
        }
        update(timePerFrame.asSeconds());
        display();
        if (_killed) {
            _game->changeScene(_nextSceneName);
            _killed = false;
            return;
        }
    }
}

void Scene::killScene() {
    _killed = true;
}

sf::View* Scene::getPtrView() {
    return &_view;
}

void Scene::processInput() {
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {_window->close(); exit(0);}
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            _window->close(); exit(0);
        }
    }
}

void Scene::update(float deltaTime) {
    (void)deltaTime;

}

void Scene::render() {
    render(_window);
}

void Scene::render(sf::RenderTarget* target) {
    (void) target;
}

void Scene::display() {
    _window->clear();
    _window->setView(_view);
    render();
    _window->setView(_window->getDefaultView());
    _window->display();
}

void Scene::initView(sf::Vector2i windowSize) {
    int windowX = _window->getSize().x, windowY = _window->getSize().y;
    
    float xr = windowX / float(windowSize.x);
    float yr = windowY / float(windowSize.y);

    float aux;
    if (xr < yr) aux = 1/yr;
    else aux = 1/xr;
    
    xr *= aux;
    yr *= aux;
    sf::Vector2f min,max;

    min.x = (1.f - yr) / 2.f;
    min.y = (1.f - xr) / 2.f;
    max.x = 1.f - min.x*2;
    max.y = 1.f - min.y*2;

    _view.reset(sf::FloatRect(0,0,windowSize.x,windowSize.y));
    _view.setViewport(sf::FloatRect(min.x,min.y,max.x,max.y));
}

void Scene::changeScene(std::string nextScene) {
    _killed = true;
    _nextSceneName = nextScene;
}
