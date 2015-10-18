#include "Resources.hpp"

// sf::Texture        Resources::....
// sf::Shader             Resources::DtO;
 sf::Font               Resources::pauseMenuFont;

sf::Texture               Resources::textureTest;
sf::Texture               Resources::penguin;
sf::Texture               Resources::penguin1;
sf::Texture               Resources::penguin2;
sf::Texture               Resources::penguin3;
sf::Texture               Resources::penguin4;
std::vector<sf::Texture>  Resources::layer0(1);
std::vector<sf::Texture>  Resources::layer1(2);
std::vector<sf::Texture>  Resources::layer2(2);
sf::Texture               Resources::ice;

void Resources::load() {
    ice.loadFromFile(TEXTURETPATH+std::string("ice.png"));
    layer0[0].loadFromFile(TEXTURETPATH+std::string("layer0.png"));
    layer1[0].loadFromFile(TEXTURETPATH+std::string("layer10.png"));
    layer1[1].loadFromFile(TEXTURETPATH+std::string("layer11.png"));
    layer2[0].loadFromFile(TEXTURETPATH+std::string("layer20.png"));
    layer2[1].loadFromFile(TEXTURETPATH+std::string("layer21.png"));
    textureTest.loadFromFile(TEXTURETPATH+std::string("textureTest.png"));
    penguin.loadFromFile(TEXTURETPATH+std::string("paintedpenguin.png"));
    penguin1.loadFromFile(TEXTURETPATH+std::string("penguin1.png"));
    penguin2.loadFromFile(TEXTURETPATH+std::string("penguin2.png"));
    penguin3.loadFromFile(TEXTURETPATH+std::string("penguin3.png"));
    penguin4.loadFromFile(TEXTURETPATH+std::string("penguin4.png"));

    //  if (!DtO.loadFromFile(SHADERPATH+std::string("transitionDtO.frag"), sf::Shader::Fragment)) exit(EXIT_FAILURE);

    if (!pauseMenuFont.loadFromFile("Resources/Fonts/Font.ttf")) exit(EXIT_FAILURE);

}


