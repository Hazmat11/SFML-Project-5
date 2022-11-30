#pragma once

#include <SFML/Graphics.hpp>

#define PROJECTILE_TEXTURE_PATH "img/boule_elek.png"



class Projectiles
{
public:

	Projectiles();
	Projectiles(float pos_x, float pos_y, float dir_x, float dir_y);
	~Projectiles();

	void setProjectileCollisions();

	void projectileRender(sf::RenderWindow* win);
	void projoLoop();

	int projoLifeTime = 300;
	int projoActualTL = 0;


private:
	sf::Sprite projectileSprite;
	sf::Texture projectileTexture;
	sf::FloatRect projectileBox;
	sf::Vector2f Dir;

	float speed = 10;
	int a = 0;

	void showProjectileTexture();
};

