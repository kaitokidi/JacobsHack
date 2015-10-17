#include "Resources.hpp"

// sf::Texture        Resources::....
// sf::Shader             Resources::DtO;
 sf::Font               Resources::pauseMenuFont;

sf::Texture            Resources::textureTest;
sf::Texture 	Resources::penguin;

void Resources::load() {
    textureTest.loadFromFile(TEXTURETPATH+std::string("textureTest.png"));
    penguin.loadFromFile(TEXTURETPATH+std::string("paintedpenguin.png"));
    //  if (!DtO.loadFromFile(SHADERPATH+std::string("transitionDtO.frag"), sf::Shader::Fragment)) exit(EXIT_FAILURE);

    if (!pauseMenuFont.loadFromFile("Resources/Fonts/font.otf")) exit(EXIT_FAILURE);

}


