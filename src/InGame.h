#pragma once
#include "Player.h"
#include "Ennemies.h"


class InGame {
public :
	Ennemies ennemies;
	Player player;

	InGame();
	~InGame();
	void GameLoop();
	void Render(sf::RenderWindow* win);
private :

};