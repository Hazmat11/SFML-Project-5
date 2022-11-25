#include "InGame.h"

InGame::InGame() {

}
InGame::~InGame() {

}

void InGame::GameLoop() {
	ennemies.ennemiesTexture();
	player.playerTexture();
	ennemies.setEnnemiesCollisions();
	player.movePlayer();
}

void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map.actualMap);
	window->draw(player.playerSprite);
	window->draw(ennemies.ennemiesSprite);
}