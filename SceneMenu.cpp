#include "SceneMenu.hpp"
#include "Game.hpp"

SceneMenu::SceneMenu(Game* g, sf::RenderWindow* w) : Scene(g,w),_menu(*w) {

    sf::Vector2u targetResolution(640,360);
    initView(sf::Vector2i(targetResolution));
    sf::Vector2u displayResolution(_view.getSize());
    _bg = new Background(displayResolution);

    VLayout* layout = new VLayout;
    layout->setSpace(5);

    TextButton* resB;
    resB = new TextButton("     Play Solo", Resources::pauseMenuFont);
    resB->onClick = [this](const sf::Event&, Button&){ changeScene("Jump", 1); };

    TextButton* resB2;
    resB2 = new TextButton("     Play 1v1", Resources::pauseMenuFont);
    resB2->onClick = [this](const sf::Event&, Button&){ changeScene("Jump", 2); };

    TextButton* resB3;
    resB3 = new TextButton("     Play Three", Resources::pauseMenuFont);
    resB3->onClick = [this](const sf::Event&, Button&){ changeScene("Jump", 3); };

    TextButton* resB4;
    resB4 = new TextButton("     Play Four", Resources::pauseMenuFont);
    resB4->onClick = [this](const sf::Event&, Button&){ changeScene("Jump", 4); };

    TextButton* exitB;
    exitB = new TextButton("     Exit", Resources::pauseMenuFont);
    exitB->onClick = [this](const sf::Event&, Button&){ exit(0); };
    layout->add(resB);
    layout->add(resB2);
    layout->add(resB3);
    layout->add(resB4);
    layout->add(exitB);
    _menu.setLayout(layout);

}

SceneMenu::~SceneMenu() {
    delete _bg;
}

void SceneMenu::processInput() {
    sf::Event event;
    while (_window->pollEvent(event)) {
        _menu.processEvent(event);
    }
}

void SceneMenu::update(float deltaTime) {
    _bg->update(deltaTime);
}

void SceneMenu::render() {
    render(_window);
}

void SceneMenu::render(sf::RenderTarget* target) {
    _bg->draw(target);

    target->setView(target->getDefaultView());
    _menu.draw();
    target->setView(_view);
}
