#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Projectiles.h"
#include <SFML/Audio.hpp>
#define JIGGLY_TEXTURE_PATH "img/tilesJiggly.png"
#define JIGGLYPUFF_HURT_SOUND_PATH "sounds/jigglyoof.wav"

class Ennemies
{
public:
	Player* player;
	Projectiles* projectiles;

	Ennemies();
	~Ennemies();
	void setEnemy(Player* p);
	void arrangeSprite();
	void ennemiesLoop();
	void ennemiesTexture();
	void refreshTexture();
	void setEnnemiesCollisions();
	void playerTakeDamage();
	void moveEnemyX();
	void moveEnemyY();
	void enemyLoop();
	void takeDamage();
	bool systemHP();


	sf::Sprite ennemiesSprite;
	sf::Texture texture;
	sf::FloatRect ennemiesBox;

	int HP = 2;
	bool deleteSprite;

	sf::SoundBuffer buffer;
	sf::Sound jigglyoofSound;

private:
	int frame = 0;
	int time = 0;
	bool invincible;
	int enemySpeed = 3;
	bool faceRight = false;
	bool faceLeft = false;


};

