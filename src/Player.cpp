#include "Player.h"

Player::Player() {
	arrangeSprite();
	setPlayerCollisions();
	texture.loadFromFile(PIKACHU_TEXTURE_PATH);
}

Player::~Player() {

}

sf::Vector2f Player::returnPos(){
	playerPosition = playerSprite.getPosition();
	playerSprite.setPosition(playerPosition);
	return playerPosition; 
}

void Player::wallCollision() {
	returnPos();
	if (playerPosition.x > 1635) {
		playerSprite.move(-3.f, 0.f);
	}
	if (playerPosition.y < 135) {
		playerSprite.move(0.f, 3.f);
	}
	if (playerPosition.x < 175) {
		playerSprite.move(3.f, 0.f);
	}
	if (playerPosition.y > 830) {
		playerSprite.move(0.f, -3.f);
	}
}

void Player::movePlayer() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		playerSprite.move(3.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		playerSprite.move(-3.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		playerSprite.move(0.f, -3.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerSprite.move(0.f, 3.f);
	}
}

void Player::playerShoot()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		shootTimer = 0;

		Projectiles prj;
		prj.projectileSprite.setPosition(returnPos());

		this->direction = RIGHT;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		shootTimer = 0;

		listeProjectiles.push_back(Projectiles(projectile));

		this->direction = LEFT;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		shootTimer = 0;

		listeProjectiles.push_back(Projectiles(projectile));

		this->direction = UP;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))		//A faire: incrémenter shootTimer dans la fonction Update
	{
		shootTimer = 0;

		listeProjectiles.push_back(Projectiles(projectile));

		this->direction = DOWN;

	}
}

void Player::playerHP(sf::RenderWindow* window) {
	if (HP == 0) {
		window->close();
	}
}


void Player::playerTexture()
{

	if (frame < 30) {
		switch (direction) {
		default:
			playerSprite.setTextureRect(sf::IntRect(10, 10, 60, 60));
			break;
		case 1:
			playerSprite.setTextureRect(sf::IntRect(10, 140, 60, 60));
			break;
		case 2:
			playerSprite.setTextureRect(sf::IntRect(10, 75, 60, 60));
			break;
		case 3:
			playerSprite.setTextureRect(sf::IntRect(10, 200, 60, 60));
			break;
		case 4:
			playerSprite.setTextureRect(sf::IntRect(10, 10, 60, 60));
			break;
		}
		playerSprite.setTexture(texture);
		frame++;
	}
	if (frame < 60 && frame > 29) {
		switch (direction) {
		default:
			playerSprite.setTextureRect(sf::IntRect(140, 10, 60, 60));
			break;
		case 1 :
			playerSprite.setTextureRect(sf::IntRect(140, 140, 60, 60));
			break;
		case 2:
			playerSprite.setTextureRect(sf::IntRect(140, 75, 60, 60));
			break;
		case 3:
			playerSprite.setTextureRect(sf::IntRect(140, 200, 60, 60));
			break;
		case 4:
			playerSprite.setTextureRect(sf::IntRect(140, 10, 60, 60));
			break;
		}
		playerSprite.setTexture(texture);
		frame++;
	}

	if (frame == 60) {
		frame = 0;
	}
}

void Player::arrangeSprite()
{
	playerSprite.scale(sf::Vector2f(2.3f, 2.3f));
	playerSprite.setPosition(sf::Vector2f(555.f, 325.f));
}

void Player::setPlayerCollisions()
{
	playerBox = playerSprite.getGlobalBounds();
}

void Player::projectilePosition(sf::Sprite projectile)
{
	projectile.setPosition(playerPosition.x, playerPosition.y);
}

void Player::playerRender(sf::RenderWindow* window) 
{
	window->draw(playerSprite);


}