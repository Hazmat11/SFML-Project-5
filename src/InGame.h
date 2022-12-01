#pragma once
#include "Player.h"
#include "Map.h"
#include "Ennemies.h"
#include "Projectiles.h"


class InGame {
public :
	Ennemies* ennemies;
	Player player;
	Map* map;
	Projectiles* projectile;

	InGame();
	~InGame();
	void GameLoop(sf::RenderWindow* win);
	void Render(sf::RenderWindow* win);
	void projCollision();
private :

};