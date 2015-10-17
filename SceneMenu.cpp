#include "SceneMenu.hpp"
#include "Game.hpp"

SceneMenu::SceneMenu(Game* g, sf::RenderWindow* w) : Scene(g,w),_menu(*w) {

    VLayout* layout = new VLayout;
    layout->setSpace(25);
    TextButton* resB;
    resB = new TextButton("Resume", Resources::pauseMenuFont);
    resB->onClick = [this](const sf::Event&, Button&){ changeScene("jump"); };
    TextButton* exitB;
    exitB = new TextButton("Exit", Resources::pauseMenuFont);
    exitB->onClick = [this](const sf::Event&, Button&){ exit(0); };
    layout->add(exitB);
    layout->add(resB);
    _menu.setLayout(layout);

}

SceneMenu::~SceneMenu() {}

void SceneMenu::update(float deltaTime) {
    //bg.update(deltaTime);


}

void SceneMenu::render() {
    render(_window);
}

void SceneMenu::render(sf::RenderTarget* target) {

}
