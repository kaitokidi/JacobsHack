#include "Resources.hpp"

// sf::Texture        Resources::....
// sf::Shader             Resources::DtO;
 sf::Font               Resources::pauseMenuFont;

sf::Texture             Resources::textureTest;
sf::Texture             Resources::penguin;
sf::Texture             Resources::penguin1;
sf::Texture             Resources::penguin2;
sf::Texture             Resources::penguin3;
sf::Texture             Resources::penguin4;
sf::Texture             Resources::layer0;

void Resources::load() {
    layer0.loadFromFile(TEXTURETPATH+std::string("layer0.png"));
    textureTest.loadFromFile(TEXTURETPATH+std::string("textureTest.png"));
    penguin.loadFromFile(TEXTURETPATH+std::string("paintedpenguin.png"));
    penguin1.loadFromFile(TEXTURETPATH+std::string("penguin1.png"));
    penguin2.loadFromFile(TEXTURETPATH+std::string("penguin2.png"));
    penguin3.loadFromFile(TEXTURETPATH+std::string("penguin3.png"));
    penguin4.loadFromFile(TEXTURETPATH+std::string("penguin4.png"));

    //  if (!DtO.loadFromFile(SHADERPATH+std::string("transitionDtO.frag"), sf::Shader::Fragment)) exit(EXIT_FAILURE);

    if (!pauseMenuFont.loadFromFile("Resources/Fonts/font.otf")) exit(EXIT_FAILURE);

}


