#ifndef __RESOURCES_HPP__
#define __RESOURCES_HPP__

#include "utils.hpp"

class Resources {
public:
    static void load();
    //static sf::Texture ...
    //static sf::Shader  DtO;
    static sf::Texture ice;
    static sf::Texture penguin;
    static std::vector<sf::Texture>layer0;
    static std::vector<sf::Texture>layer1;
    static std::vector<sf::Texture>layer2;
    static sf::Texture penguin1;
    static sf::Texture penguin2;
    static sf::Texture penguin3;
    static sf::Texture penguin4;
    static sf::Texture textureTest;
    static sf::Font pauseMenuFont;

private:

};

#endif
