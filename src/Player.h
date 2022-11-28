#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Projectiles.h"

#define RIGHT 1;
#define LEFT 2;
#define UP 3;
#define DOWN 4;
#define PIKACHU_TEXTURE_PATH "img/player.png"


class Player
{
public :

	Projectiles projectile;

	Player();
	~Player();

	sf::Sprite playerSprite;
	sf::Texture texture;
	sf::FloatRect playerBox;

	void movePlayer();
	void playerTexture();
	void arrangeSprite();
	void setPlayerCollisions();
	int playerHP();
	void playerShoot();

	void playerRender(sf::RenderWindow* win);

	void projectilePosition(sf::Sprite);

	sf::Vector2f returnPos(const int, const int);

	sf::Vector2f playerPosition;

	std::vector<Projectiles> listeProjectiles;


private :
	int maxHP = 4;
	int frame = 0;
	int direction;
	int shootTimer = 0;
};

