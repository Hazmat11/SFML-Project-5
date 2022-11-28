#pragma once

#include <SFML/Graphics.hpp>

#define PROJECTILE_TEXTURE_PATH "img/boule_elek.png"



class Projectiles
{
public:

	Projectiles();
	Projectiles(float direction);
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

