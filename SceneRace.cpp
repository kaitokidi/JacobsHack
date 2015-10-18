#include "SceneRace.hpp"
#include "Game.hpp"

SceneRace::SceneRace(Game* g, sf::RenderWindow* w) : Scene(g,w) {
	sf::Vector2u targetResolution(640,360);
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

    _players[0].setMass(80);
    _players[1].setMass(60);
    _players[2].setMass(40);
    _players[3].setMass(20);


	// for (int i = 0; i < _nPlayers; ++i) _players[i].setPosition(i*40,40);
	_background = new Background(displayResolution);


	_rect.setSize(sf::Vector2f(displayResolution.x, displayResolution.y));
	_rect.setPosition(sf::Vector2f(-0.5*displayResolution.x,displayResolution.y*3.0/4.0));
    //_rect.setFillColor(sf::Color::Yellow);
	_rect2.setSize(sf::Vector2f(displayResolution.x, displayResolution.y));
    _rect2.setPosition(sf::Vector2f(0.5*displayResolution.x-1,displayResolution.y*3.0/4.0));
    //_rect2.setFillColor(sf::Color::Red);
	_rect3.setSize(sf::Vector2f(displayResolution.x, displayResolution.y));
    _rect3.setPosition(sf::Vector2f(1.5*displayResolution.x-1,displayResolution.y*3.0/4.0));
    //_rect3.setFillColor(sf::Color::Blue);

    _rect.setTexture(&Resources::ice, true);
    _rect2.setTexture(&Resources::ice, true);
    _rect3.setTexture(&Resources::ice, true);

	_groundBounds = sf::IntRect(0,displayResolution.y*3.0/4.0,displayResolution.x, displayResolution.y/4.0);
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
            std::cout<<"bñasldjasdf"<<std::endl;
           _game->start();
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
            setRotation(_rotation+0.2);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
            setRotation(_rotation-0.2);
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
            //_players[0].setVelocity(sf::Vector2f(_players[0].velocity().x, -50));
            _players[0].setVelocity(sf::Vector2f(_players[0].velocity().x, 0));
            _players[0].setAcceleration(sf::Vector2f(0,-200000));
            _players[0].setJumping(true);

        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L) {
            if(_nPlayers >= 1) {
//                _players[1].setVelocity(sf::Vector2f(_players[1].velocity().x, -50));
                _players[1].setVelocity(sf::Vector2f(_players[1].velocity().x, 0));
                _players[1].setAcceleration(sf::Vector2f(0,-200000));
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
	if (_rect.getPosition().x  < -1.5*_view.getSize().x) _rect.move( sf::Vector2f(3*_view.getSize().x,0));
	else if(_rect.getPosition().x  > 1.5*_view.getSize().x) _rect.move( sf::Vector2f(-3*_view.getSize().x,0));
	if (_rect2.getPosition().x < -1.5*_view.getSize().x) _rect2.move(sf::Vector2f(3*_view.getSize().x,0));
	else if(_rect2.getPosition().x  > 1.5*_view.getSize().x) _rect2.move( sf::Vector2f(-3*_view.getSize().x,0));
	if (_rect3.getPosition().x < -1.5*_view.getSize().x) _rect3.move(sf::Vector2f(3*_view.getSize().x,0));
	else if(_rect3.getPosition().x  > 1.5*_view.getSize().x) _rect3.move( sf::Vector2f(-3*_view.getSize().x,0));

	for (int i = 0; i < _nPlayers; ++i) {
        //float maxRotation = 45;
        float rot = _rotation > 180 ? _rotation - 360 : _rotation;
        if(rot > 45 ) rot = 45;
        if(rot < -45) rot = -45;

        //float destination = (-rot+maxRotation)*_view.getSize().x/(maxRotation*2);

//        std::cout << _players[i].velocity().x << " - " << _players[i].mass()*0.5 << " + " <<
         //_players[i].mass()*0.8*(1- _players[i].getPosition().x/640) << " + " << -rot << std::endl;
        float newSpeed =
                _players[i].velocity().x
                - _players[i].mass()*0.2
                + _players[i].mass()*0.8*(1- _players[i].getPosition().x/640) *(-1*rot)
                ;
        newSpeed *= 10;
        if(_players[i].jumping())newSpeed*=0.6;
        newSpeed *= deltaTime;


        float velY = _players[i].velocity().y + _players[i].acceleration().y * deltaTime;
        _players[i].setAcceleration(sf::Vector2f(0, _players[i].acceleration().y + _players[i].mass()*2222 * deltaTime));

        _players[i].setVelocity(sf::Vector2f(newSpeed,velY*deltaTime));
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
        for(int p = 0; p < _players.size(); ++p){

            sf::IntRect colision;
            if(p != i){
                if(_players[i].getMGlobalBounds().intersects(_players[p].getMGlobalBounds(), colision)){
                    if(_players[i].velocity().y > 0 && _players[i].velocity().y > _players[p].velocity().y){
                        _players[i].setPosition(_players[i].getPosition().x, colision.top-_players[i].getMGlobalBounds().height);
                    }
                    else if(_players[i].velocity().y < 0 && _players[i].velocity().y < _players[p].velocity().y){
                        _players[i].setPosition(_players[i].getPosition().x, colision.top + colision.height);
                    }
                    else if(_players[i].velocity().x > 0 && _players[i].velocity().x > _players[p].velocity().x ){
                        _players[i].setPosition(colision.left-_players[i].getMGlobalBounds().width, _players[i].getPosition().y);
                    }
                    else if(_players[i].velocity().x < 0 && _players[i].velocity().x < _players[p].velocity().x ){
                        _players[i].setPosition(colision.left+colision.width, _players[i].getPosition().y);
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
