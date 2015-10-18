#include "SceneRace.hpp"
#include "Game.hpp"



SceneRace::SceneRace(Game* g, sf::RenderWindow* w) : Scene(g,w) {
	sf::Vector2u targetResolution(TARGETRESOLUTIONX,TARGETRESOLUTIONY);
	initView(sf::Vector2i(targetResolution));
	sf::Vector2u displayResolution(_view.getSize());

	_speed = 0;
	_nPlayers = 4;
	_rotation = 0;
	_players = std::vector<Player>(_nPlayers);

    _players[0].setTexture(Resources::penguin1);
    _players[1].setTexture(Resources::penguin2);
    _players[2].setTexture(Resources::penguin3);
    _players[3].setTexture(Resources::penguin4);

    _players[0].setMass(180);
    _players[1].setMass(160);
    _players[2].setMass(140);
    _players[3].setMass(120);


	for (int i = 0; i < _nPlayers; ++i) _players[i].setPosition((i+1)*60,40);
	_background = new Background(displayResolution);


	_rect.setSize(sf::Vector2f(targetResolution.x, displayResolution.y));
	_rect.setPosition(sf::Vector2f(-0.5*targetResolution.x,displayResolution.y*3.0/4.0));
    //_rect.setFillColor(sf::Color::Yellow);
	_rect2.setSize(sf::Vector2f(targetResolution.x, displayResolution.y));
    _rect2.setPosition(sf::Vector2f(0.5*targetResolution.x-1,displayResolution.y*3.0/4.0));
    //_rect2.setFillColor(sf::Color::Red);
	_rect3.setSize(sf::Vector2f(targetResolution.x, displayResolution.y));
    _rect3.setPosition(sf::Vector2f(1.5*targetResolution.x-1,displayResolution.y*3.0/4.0));
    //_rect3.setFillColor(sf::Color::Blue);

    _rect.setTexture(&Resources::ice, true);
    _rect2.setTexture(&Resources::ice, true);
    _rect3.setTexture(&Resources::ice, true);

	_groundBounds = sf::IntRect(0,displayResolution.y*3.0/4.0,targetResolution.x, displayResolution.y/4.0);
}

SceneRace::~SceneRace() {
	delete _background;
}

void SceneRace::init(int nPlayers) {
	_nPlayers = nPlayers;
	_rotation = 0;
}

void SceneRace::processInput() {
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {_window->close(); exit(0);}
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
           changeScene("Menu",0);
        }

        /*
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
            setRotation(_rotation+0.2);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
            setRotation(_rotation-0.2);
        }

        */

        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
            //_players[0].setVelocity(sf::Vector2f(_players[0].velocity().x, -50));
            if (_players[0].jumping()) continue;
            _players[0].setVelocity(sf::Vector2f(_players[0].velocity().x, -200));
            _players[0].setJumping(true);

        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L) {
            if(_nPlayers >= 1) {
//                _players[1].setVelocity(sf::Vector2f(_players[1].velocity().x, -50));
            	if (_players[1].jumping()) continue;
                _players[1].setVelocity(sf::Vector2f(_players[0].velocity().x, -200));
                _players[1].setJumping(true);
            }
        }
    }
}


void SceneRace::update(float deltaTime) {

//	if(! sf::Keyboard::isKeyPressed(sf::Keyboard::A)){_players[0].setJumping(false);}
    //if(! sf::Keyboard::isKeyPressed(sf::Keyboard::L)){ if(_nPlayers >= 1) _players[1].setJumping(false);}

	_rotation = (_rotation < 0 ? _rotation + 360 : (_rotation > 360? _rotation - 360 : _rotation) );
	_speed += 0.5*sin(_rotation*TO_RADIANS)*TO_DEGREES*deltaTime;
	_speed = std::min(50.0f, std::max(_speed,-50.0f));
    float groundSpeed = std::min(50.0f, std::max(_rotation > 180 ? _rotation - 360 : _rotation,-50.0f));
    //if(_rotation > 90) groundSpeed = 360 - _rotation +5;
    _rect.move(sf::Vector2f(groundSpeed,0));
    _rect2.move(sf::Vector2f(groundSpeed,0));
    _rect3.move(sf::Vector2f(groundSpeed,0));
    _background->setSpeed(groundSpeed);
    _background->update(deltaTime);
	if (_rect.getPosition().x  < -1.5*TARGETRESOLUTIONX) _rect.move( sf::Vector2f(3*TARGETRESOLUTIONX,0));
	else if(_rect.getPosition().x  > 1.5*TARGETRESOLUTIONX) _rect.move( sf::Vector2f(-3*TARGETRESOLUTIONX,0));
	if (_rect2.getPosition().x < -1.5*TARGETRESOLUTIONX) _rect2.move(sf::Vector2f(3*TARGETRESOLUTIONX,0));
	else if(_rect2.getPosition().x  > 1.5*TARGETRESOLUTIONX) _rect2.move( sf::Vector2f(-3*TARGETRESOLUTIONX,0));
	if (_rect3.getPosition().x < -1.5*TARGETRESOLUTIONX) _rect3.move(sf::Vector2f(3*TARGETRESOLUTIONX,0));
	else if(_rect3.getPosition().x  > 1.5*TARGETRESOLUTIONX) _rect3.move( sf::Vector2f(-3*TARGETRESOLUTIONX,0));

	for (int i = 0; i < _nPlayers; ++i) {
        //float maxRotation = 45;
        float rot = _rotation > 180 ? _rotation - 360 : _rotation;
        if(rot > 45 ) rot = 45;
        if(rot < -45) rot = -45;

        //float destination = (-rot+maxRotation)*TARGETRESOLUTIONX/(maxRotation*2);

//        std::cout << _players[i].velocity().x << " - " << _players[i].mass()*0.5 << " + " <<
         //_players[i].mass()*0.8*(1- _players[i].getPosition().x/TARGETRESOLUTIONX) << " + " << -rot << std::endl;
        float newSpeed =
                _players[i].velocity().x
                - _players[i].mass()*0.2
                + _players[i].mass()*0.8*(1- _players[i].getPosition().x/TARGETRESOLUTIONX) *(-1*rot)
                ;
        newSpeed *= 0.1;
		if(_players[i].jumping())newSpeed*=0.8;
        // newSpeed *= deltaTime;


        float velY = _players[i].velocity().y + _players[i].acceleration().y * deltaTime;
        _players[i].setAcceleration(sf::Vector2f(0, 1*_players[i].mass()));
        _players[i].setVelocity(sf::Vector2f(newSpeed,velY));
        _players[i].move(deltaTime);
		if (_players[i].getPosition().y > _groundBounds.top - _players[i].getMBounds().height) {
			_players[i].setPosition(_players[i].getPosition().x, _groundBounds.top-_players[i].getMBounds().height);
			_players[i].setJumping(false);
            _players[i].setVelocity(sf::Vector2f(_players[i].velocity().x, 0));
		}
        if(_players[i].getPosition().x < -250){
            _players[i].setPosition(-200, _players[i].getPosition().y);
            _players[i].setVelocity(sf::Vector2f(0,0));
        }
        sf::FloatRect a = _players[i].getMGlobalBounds();
        Player &p1 = _players[i];
        for(int p = i+1; p < _nPlayers; ++p){
        	Player &p2 = _players[p];
        	// if (p == i) continue;
            sf::FloatRect c;
        	sf::FloatRect b = p2.getMGlobalBounds();
            if(a.intersects(b, c)) {
            	float m1 = p1.mass(), m2 = p2.mass();
            	sf::Vector2f v1 = ((m1-m2)/(m1+m2))*p1.velocity() + ((2*m2)/(m1+m2))*p2.velocity();
            	sf::Vector2f v2 = ((m1-m2)/(m1+m2))*p2.velocity() + ((2*m2)/(m1+m2))*p1.velocity();
            	// std::cout << c.left << " " << c.top << " " << c.width << " " << c.height << std::endl;
            	if (c.width < c.height) {
            		p1.setVelocity(sf::Vector2f(v1.x,p1.velocity().y));
            		p2.setVelocity(sf::Vector2f(v2.x,p2.velocity().y));
            		if (p1.getPosition().x < p2.getPosition().x) {
            			p1.setPosition(p1.getPosition().x-c.width/2,p1.getPosition().y);
            			p2.setPosition(p2.getPosition().x+c.width/2,p2.getPosition().y);
            		}
            		else {
            			p1.setPosition(p1.getPosition().x+c.width/2,p1.getPosition().y);
            			p2.setPosition(p2.getPosition().x-c.width/2,p2.getPosition().y);
            		}
            	}
            	else {
            		if (p1.jumping() || p2.jumping()) {
            		p1.setVelocity(sf::Vector2f(p1.velocity().x,v1.y));
            		p2.setVelocity(sf::Vector2f(p2.velocity().x,v2.y));
            		}
            		if (p1.getPosition().y < p2.getPosition().y) {
            			p1.setPosition(p1.getPosition().x,p1.getPosition().y-c.height);
            			p1.setJumping(false);
            			p2.setPosition(p2.getPosition().x,p2.getPosition().y);
            		}
            		else {
            			p1.setPosition(p1.getPosition().x,p1.getPosition().y);
            			p2.setPosition(p2.getPosition().x,p2.getPosition().y-c.height);
            			p2.setJumping(false);
            		}
            	}
            }
        }
	}
}
	
void SceneRace::render(sf::RenderTarget* target) {
	_background->draw(target);

	target->draw(_rect);
	target->draw(_rect2);
	target->draw(_rect3);
	for (int i = 0; i < _nPlayers; ++i) target->draw(_players[i]);
}


void SceneRace::setRotation(float rotation) {
	_rotation = rotation;
	_background->setRotation(_rotation);
    _view.setRotation(_rotation);
}

