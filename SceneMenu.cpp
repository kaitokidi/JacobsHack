#include "SceneMenu.hpp"
#include "Game.hpp"

SceneMenu::SceneMenu(Game* g, sf::RenderWindow* w) : Scene(g,w),_menu(*w) {

    VLayout* layout = new VLayout;
    layout->setSpace(25);

    TextButton* resB;
    resB = new TextButton("Play Solo", Resources::pauseMenuFont);
    resB->onClick = [this](const sf::Event&, Button&){ changeScene("jump", 1); };

    TextButton* resB2;
    resB2 = new TextButton("Play 1v1", Resources::pauseMenuFont);
    resB2->onClick = [this](const sf::Event&, Button&){ changeScene("jump", 2); };

    TextButton* resB3;
    resB3 = new TextButton("Play Three", Resources::pauseMenuFont);
    resB3->onClick = [this](const sf::Event&, Button&){ changeScene("jump", 3); };

    TextButton* resB4;
    resB4 = new TextButton("Play Four", Resources::pauseMenuFont);
    resB4->onClick = [this](const sf::Event&, Button&){ changeScene("jump", 4); };

    TextButton* exitB;
    exitB = new TextButton("Exit", Resources::pauseMenuFont);
    exitB->onClick = [this](const sf::Event&, Button&){ exit(0); };
    layout->add(exitB);
    layout->add(resB);
    layout->add(resB2);
    layout->add(resB3);
    layout->add(resB4);
    _menu.setLayout(layout);

}

SceneMenu::~SceneMenu() {}

void SceneMenu::update(float deltaTime) {
    //bg.update(deltaTime);
    sf::Event event;
    while (_window->pollEvent(event)) {
        _menu.processEvent(event);
    }

}

void SceneMenu::render() {
    render(_window);
}

void SceneMenu::render(sf::RenderTarget* target) {
    _bg.draw(target);
    _menu.draw();
}
