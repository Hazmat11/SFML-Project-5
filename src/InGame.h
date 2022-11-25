#pragma once   
#include <SFML/Graphics.hpp>

class InGame {
public :
	InGame();
	~InGame();
	void GameLoop();
	void Render(sf::RenderWindow* win);
private :

};