#include "InGame.h"

InGame::InGame() {
	ennemies = new Ennemies(&player);
	map = new Map(&player);
}

InGame::~InGame() {

}

void InGame::GameLoop(sf::RenderWindow* win) {
	player.playerLoop(win);
	ennemies->ennemiesTexture();
	ennemies->setEnnemiesCollisions();
}

void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map->actualMap);
	window->draw(ennemies->ennemiesSprite);
	player.playerRender(window);
}