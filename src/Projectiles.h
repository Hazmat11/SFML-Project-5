#pragma once

#include <SFML/Graphics.hpp>

#define PROJECTILE_TEXTURE_PATH "img/boule_elek.png"



class Projectiles
{
public:

	Projectiles();
	Projectiles(float pos_x, float pos_y, float dir_x, float dir_y);
	~Projectiles();

	sf::Sprite projectileSprite;
	sf::Texture projectileTexture;
	sf::FloatRect projectileBox;

	void showProjectileTexture();
	void projectileArrangeSprite();
	void setProjectileCollisions();

	void projectileRender(sf::RenderWindow* win);
	void projoLoop();


private:

	int a = 0;


};

