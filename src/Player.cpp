#include "Player.h"
#include "texture.h"

Player::Player() {
}

Player::~Player() {

}

sf::Vector2f Player::returnPos(const int playerX, const int playerY){
	playerSprite.setPosition(100, 500);
	sf::Vector2f position = playerSprite.getPosition();
	std::cout << position.x << " " << position.y << "\n";
	return position; 
}

void Player::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
		playerSprite.move(1.f, 0.f);
		playerSprite.getPosition();
    }

	/*switch sf::Keyboard::isKeyPressed{
	switch sf::Keyboard::Right{
		playerSprite.move(1.f, 0.f);
	}
	}*/
}

void Player::showTexture()
{
	if (a < 30) {
		texture.loadFromFile("img/player.png", sf::IntRect(10, 10, 60, 60));
		playerSprite.setTexture(texture);
		a++;
	}

	if (a < 60 && a > 29) {
		texture.loadFromFile("img/player.png", sf::IntRect(140, 10, 60, 60));
		playerSprite.setTexture(texture);
		a++;
	}

	if (a == 60) {
		a = 0;
	}
}