#include "InGame.h"

InGame::InGame() {
	ennemies = new Ennemies(&player);
	enemiesList.push_back(ennemies);
	map = new Map(&player);
}

void InGame::projCollision() {
	for (int i = 0; i < player.projos.size(); i++)
	{
		if (ennemies->ennemiesBox.contains(player.projos[i].projectileSprite.getPosition())) {
			player.projos.erase(player.projos.begin() + i);
			ennemies->HP--;
		}
	}

	for (int i = 0; i < enemiesList.size(); i++) {
		if (enemiesList[i]->systemHP()) {
			enemiesList.erase(enemiesList.begin() + i);
		}
	}
}

InGame::~InGame() {

}

void InGame::GameLoop(sf::RenderWindow* win) {
	player.playerLoop(win);
	ennemies->ennemiesLoop();
	ennemies->ennemiesTexture();
	ennemies->setEnnemiesCollisions();
	map->mapLoop();
	projCollision();
}

void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map->actualMap);
	window->draw(map->object);
	if (!ennemies->deleteSprite) {
		window->draw(ennemies->ennemiesSprite);
	}
	player.playerRender(window);
}