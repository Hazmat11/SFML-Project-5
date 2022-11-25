#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameManager {
public :
	sf::Event* e;
	sf::RenderWindow* rw;
	int index;

	struct player {
		int maxPV;
		int pv;
		float speed;
		float dmg;
		int armor;
	};
	
	GameManager();
	~GameManager();
	void setGameManager(sf::Event* event, sf::RenderWindow* renderWindow);
private :

};



