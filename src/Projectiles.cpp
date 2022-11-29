#include "Projectiles.h"



Projectiles::Projectiles()
{
}

Projectiles::~Projectiles()
{

}

Projectiles::Projectiles(float pos_x, float pos_y, float dir_x, float dir_y)
{
	projectileSprite.setPosition(pos_x, pos_y);
	projectileSprite.setScale(sf::Vector2f(4.f, 4.f));

	Dir.x = dir_x;
	Dir.y = dir_y;
}

void Projectiles::setProjectileCollisions()
{
	projectileBox = projectileSprite.getGlobalBounds();
}

void Projectiles::showProjectileTexture()
{
	projectileTexture.loadFromFile(PROJECTILE_TEXTURE_PATH);

	if (a < 20) {

		projectileSprite.setTextureRect(sf::IntRect(0, 0, 8, 8));
	} else if (a < 40 && a > 19) {
		projectileSprite.setTextureRect(sf::IntRect(8, 0, 8, 8));
	} else if (a < 60 && a > 39) {
		projectileSprite.setTextureRect(sf::IntRect(0, 8, 8, 8));
	} else if (a == 60) {
		a = 0;
	}
	projectileSprite.setTexture(projectileTexture);
	a++;
}

void Projectiles::projoLoop()
{
	projectileSprite.move(Dir* speed);
	if (actualTL == lifeTime) {
		delete this;
	}
	else {
		actualTL++;
	}
}

void Projectiles::projectileRender(sf::RenderWindow* window) 
{
	this->showProjectileTexture();
	window->draw(projectileSprite);
}