#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define RIGHT 1;
#define LEFT 2;
#define UP 3;
#define DOWN 4;
#define PIKACHU_TEXTURE_PATH "img/player.png"


class Player
{
public :

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

	sf::Vector2f returnPos(const int, const int);

	sf::Vector2f playerPosition;


private :
	int maxHP = 4;
	int frame = 0;
	int direction;
};

