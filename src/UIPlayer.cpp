#include "UIPlayer.h"

UIPlayer::UIPlayer() {

}

UIPlayer::UIPlayer(int lp) {
	this->maxLifePoints = lp;
	this->actualLP = lp;

	if (!pokeball.loadFromFile("img/pokeballLife.png")) {
		std::cout << "Error for Pokeball LifePoints" << std::endl;
	}
	for (int i = 0; i < maxLifePoints; i++) {
		sf::Sprite sprPoke;
		sprPoke.setTexture(pokeball);
		sprPoke.setScale(sf::Vector2f(0.45f, 0.45f));
		spritesLP.push_back(sprPoke);
	}
	
}

UIPlayer::~UIPlayer() {

}

//Update the health of the player at each frame
void UIPlayer::updateHealth(int lp) {
	this->actualLP = lp;
}

//Show hearts depending on the player's HP
void UIPlayer::DisplayHealth(sf::RenderWindow* window) {
	for (int i = 0; i < actualLP; i++) {
		spritesLP[i].setPosition(sf::Vector2f((75.0f * i) + 25.0f, 25.0f));
		window->draw(spritesLP[i]);
	}
}