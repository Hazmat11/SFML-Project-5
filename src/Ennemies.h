#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#define JIGGLY_TEXTURE_PATH "img/tilesJiggly.png"

class Ennemies
{
public:
	Player* player;

	Ennemies();
	Ennemies(Player* p);
	~Ennemies();
	void arrangeSprite();
	void ennemiesTexture();
	void refreshTexture();
	void setEnnemiesCollisions();
	void playerTakeDamage();
	void moveEnemyX();
	void moveEnemyY();
	void enemyLoop();


	sf::Sprite ennemiesSprite;
	sf::Texture texture;

private:
	int frame = 0;
	int time = 0;
	bool invincible;
	int enemySpeed = 3;

};

