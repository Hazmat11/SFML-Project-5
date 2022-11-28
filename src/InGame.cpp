#include "InGame.h"

InGame::InGame() {
	ennemies = new Ennemies(&player);
}

InGame::~InGame() {

}

void InGame::GameLoop() {
	ennemies->ennemiesTexture();
	player.playerTexture();
	player.movePlayer();
	ennemies->setEnnemiesCollisions();
}

void InGame::Render(sf::RenderWindow* window) {	
	player.playerHP(window);
	window->draw(map.actualMap);
	window->draw(player.playerSprite);
	window->draw(ennemies->ennemiesSprite);
}