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

//Manage the projectile's animations
void Projectiles::showProjectileTexture()
{
	projectileTexture.loadFromFile(PROJECTILE_TEXTURE_PATH);

	if (a < 20) {
		projectileSprite.setTextureRect(sf::IntRect(0, 0, 8, 8));
	} 
	if (a < 40 && a > 19) {
		projectileSprite.setTextureRect(sf::IntRect(8, 0, 8, 8));
	}
	if (a < 60 && a > 39) {
		projectileSprite.setTextureRect(sf::IntRect(0, 8, 8, 8));
	} 
	if (a == 60) {
		a = 0;
	}

	a += 1;
	projectileSprite.setTexture(projectileTexture);
}

//Update loop of the projectiles class for gameplay elements
void Projectiles::projoLoop()
{
	projectileSprite.move(Dir* speed);
}

//Update loop of the player class for rendered elements
void Projectiles::projectileRender(sf::RenderWindow* window) 
{
	this->showProjectileTexture();
	window->draw(projectileSprite);
}

//Return the player's position
sf::Vector2f Projectiles::returnPos() {
	projPos = projectileSprite.getPosition();
	projectileSprite.setPosition(projPos);
	std::cout << "projPos: " << projPos.x << " " << projPos.y << "\n";
	return projPos;
}