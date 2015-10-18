#include "Portada.hpp"


    Portada::Portada() {
        open = true;
    }
    
    Portada::~Portada(){}
    
    void Portada::display(sf::RenderWindow* window){
        open = true;
        while(open){
            
            sf::Event event;
            while (window->pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    exit(0);
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) { window->close(); exit(0); }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        open = false;
                    }
                default:
                    break;
                }
            }

            t.loadFromFile("res/Portada.png");
            s.setTexture(t);
            s.scale(window->getSize().y/s.getGlobalBounds().height,window->getSize().y/s.getGlobalBounds().height);
            s.setPosition(window->getSize().x/2 - s.getGlobalBounds().width/2, 0);
            window->draw(s);

            window->display();
                
        }
        
    }
    
    void Portada::display(sf::RenderWindow* window, std::string pathImage){
        open = true;
            t.loadFromFile(pathImage);
            s = sf::Sprite();
            s.setTexture(t);
            s.scale(window->getSize().y/s.getGlobalBounds().height,window->getSize().y/s.getGlobalBounds().height);
            s.setPosition(window->getSize().x/2 - s.getGlobalBounds().width/2, 0);
        while(open){
            
            sf::Event event;
            while (window->pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) window->close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        open = false;
                    }
                default:
                    break;
                }
            }

            window->clear();
            window->draw(s);

            window->display();
                
        }
        
    }
