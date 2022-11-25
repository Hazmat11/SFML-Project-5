#pragma once
#include "Player.h"
#include "Map.h"
#include "Ennemies.h"


class InGame {
public :
	Map map;
	Ennemies ennemies;
	Player player;

	InGame();
	~InGame();
	void GameLoop();
	void Render(sf::RenderWindow* win);
private :

};