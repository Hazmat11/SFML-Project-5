#include "Player.h"

Player::Player() {
	arrangeSprite();
	texture.loadFromFile(PIKACHU_TEXTURE_PATH);
}

Player::~Player() {
}

sf::Vector2f Player::returnPos(){
	playerPosition = playerSprite.getPosition();
	playerSprite.setPosition(playerPosition);
	std::cout << "playerPos: " << playerPosition.x << " " << playerPosition.y << "\n";
	return playerPosition;
}

void Player::wallCollision() {
	returnPos();
	if (playerPosition.x > 1635) {
		playerSprite.move(-5.f, 0.f);
	}
	if (playerPosition.y < 135) {
		playerSprite.move(0.f, 5.f);
	}
	if (playerPosition.x < 175) {
		playerSprite.move(5.f, 0.f);
	}
	if (playerPosition.y > 830) {
		playerSprite.move(0.f, -5.f);
	}
}

void Player::movePlayer() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		playerSprite.move(5.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		playerSprite.move(-5.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		playerSprite.move(0.f, -5.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerSprite.move(0.f, 5.f);
	}
}

void Player::playerShoot()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (shootTimer >= 60)
		{
			shootTimer = 0;
			Projectiles projo(playerPosition.x, playerPosition.y + 20, 1, 0);
			projos.push_back(projo);
		}
		this->direction = RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (shootTimer >= 60)
		{
			shootTimer = 0;
			Projectiles projo(playerSprite.getPosition().x + 15, playerSprite.getPosition().y + 20, -1, 0);
			projos.push_back(projo);
		}
		this->direction = LEFT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (shootTimer >= 60)
		{
			shootTimer = 0;
			Projectiles projo(playerSprite.getPosition().x + 30, playerSprite.getPosition().y + 20, 0, -1);
			projos.push_back(projo);
		}
		this->direction = UP;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (shootTimer >= 60)
		{
			shootTimer = 0;
			Projectiles projo(playerSprite.getPosition().x + 30, playerSprite.getPosition().y + 40, 0, 1);
			projos.push_back(projo);
		}
		this->direction = DOWN;
	}

	for (int i = 0; i < projos.size(); i += 1)
	{
		if (projos[i].projoActualTL >= projos[i].projoLifeTime) {
			std::cout << "erase";
			projos.erase(projos.begin() + i);
		}
		else {
			projos[i].projoActualTL++;
		}
	}



	shootTimer++;

}

void Player::playerHP(sf::RenderWindow* window) {
	if (HP == 0) {
		window->close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window->close();
	}
}

void Player::playerTexture()
{

	if (frame < 30) {
		switch (direction) {
		default:
			playerSprite.setTextureRect(sf::IntRect(10, 24, 40, 50));
			break;
		case 1:
			playerSprite.setTextureRect(sf::IntRect(10, 154, 40, 50));
			break;
		case 2:
			playerSprite.setTextureRect(sf::IntRect(10, 89, 40, 50));
			break;
		case 3:
			playerSprite.setTextureRect(sf::IntRect(10, 214, 40, 50));
			break;
		case 4:
			playerSprite.setTextureRect(sf::IntRect(10, 24, 40, 50));
			break;
		}
		playerSprite.setTexture(texture);
		frame++;
	}
	if (frame < 60 && frame > 29) {
		switch (direction) {
		default:
			playerSprite.setTextureRect(sf::IntRect(140, 24, 40, 50));
			break;
		case 1 :
			playerSprite.setTextureRect(sf::IntRect(140, 154, 40, 50));
			break;
		case 2:
			playerSprite.setTextureRect(sf::IntRect(140, 89, 40, 50));
			break;
		case 3:
			playerSprite.setTextureRect(sf::IntRect(140, 214, 40, 50));
			break;
		case 4:
			playerSprite.setTextureRect(sf::IntRect(140, 24, 40, 50));
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

void Player::playerLoop(sf::RenderWindow* window) {
	playerPosition = playerSprite.getPosition();
	this->movePlayer();
	this->playerShoot();
	for (int i = 0; i < projos.size(); i++) {
		projos[i].projoLoop();
	}
	this->playerTexture();
	this->wallCollision();
	this->playerHP(window);
}

void Player::playerRender(sf::RenderWindow* window) 
{
	window->draw(playerSprite);

	for (int i = 0; i < projos.size(); i++) {
		projos[i].projectileRender(window);
	}
}