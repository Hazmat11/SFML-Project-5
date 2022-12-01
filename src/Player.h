#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include "Projectiles.h"
#include "UIPlayer.h"

#define RIGHT 1;
#define LEFT 2;
#define UP 3;
#define DOWN 4;
#define PIKACHU_TEXTURE_PATH "img/player.png"

class Player
{
public :
	Player();
	Player(Projectiles* proj);
	~Player();
	sf::Vector2f returnPos();

	Projectiles* projectile;

	void movePlayer();
	void playerTexture();
	void arrangeSprite();
	void setPlayerCollisions();
	void projCollision();
	void wallCollision();
	//void verifShoot();
	void playerHP(sf::RenderWindow* window);
	void playerShoot( );
	void playerRender(sf::RenderWindow* win);
	void playerLoop(sf::RenderWindow* window);

	sf::Vector2f playerPosition;
	sf::Sprite playerSprite;
	sf::Texture texture;
	sf::FloatRect playerBox;

	int HP = 4;
	bool shoot;

private :
	std::vector<Projectiles> projos;

	int maxHP = 4;
	int frame = 0;
	int direction;
	int shootTimer = 30;

	UIPlayer* health;
};

