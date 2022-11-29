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
	void wallCollision();
	void playerHP(sf::RenderWindow* window);
	void playerShoot();

	void playerRender(sf::RenderWindow* win);

	sf::Vector2f returnPos();

	sf::Vector2f playerPosition;

	std::vector<Projectiles> listeProjectiles;

	int HP = 4;

	int r = 0;
	int l = 0;
	int u = 0;
	int d = 0;


private :
	int maxHP = 4;
	int frame = 0;
	int direction;
	int shootTimer = 0;
};

