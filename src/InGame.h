#pragma once
#include "Player.h"
#include "Map.h"
#include "Ennemies.h"
#include "Projectiles.h"
#include <vector>


class InGame {
public :
	Ennemies enemy;
	Player player;
	Map* map;
	Projectiles projectile;

	InGame();
	~InGame();
	void GameLoop(sf::RenderWindow* win);
	void Render(sf::RenderWindow* win);
	void enemySystemHP();
private :
	std::vector<Ennemies> enemiesList;
};