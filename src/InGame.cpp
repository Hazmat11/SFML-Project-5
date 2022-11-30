#include "InGame.h"

InGame::InGame() {
	ennemies = new Ennemies(&player);
	map = new Map(&player);
}

InGame::~InGame() {

}

void InGame::GameLoop(sf::RenderWindow* win) {
	player.playerLoop(win);
	ennemies->ennemiesLoop();
	map->mapLoop();
}

void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map->actualMap);
	window->draw(map->object);
	window->draw(ennemies->ennemiesSprite);
	player.playerRender(window);
}