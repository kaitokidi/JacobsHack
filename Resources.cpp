#include "Resources.hpp"

// sf::Texture        Resources::....
// sf::Shader             Resources::DtO;
 sf::Font               Resources::pauseMenuFont;

sf::Texture            Resources::textureTest;

void Resources::load() {
    textureTest.loadFromFile(TEXTURETPATH+std::string("textureTest.png"));

    //  if (!DtO.loadFromFile(SHADERPATH+std::string("transitionDtO.frag"), sf::Shader::Fragment)) exit(EXIT_FAILURE);

    if (!pauseMenuFont.loadFromFile("Resources/Fonts/font.otf")) exit(EXIT_FAILURE);

}


