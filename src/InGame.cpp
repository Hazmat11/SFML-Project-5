#include "InGame.h"

InGame::InGame() {
	enemy.setEnemy(&player);
	enemiesList.push_back(enemy);
	map = new Map(&player);
}

InGame::~InGame() {

}

void InGame::GameLoop(sf::RenderWindow* win) {
	player.playerLoop(win);
	for (int i = 0; i < enemiesList.size(); i++) {
		enemiesList[i].ennemiesLoop();
	}
	map->mapLoop();
	enemySystemHP();
}

void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map->actualMap);
	window->draw(map->object);
	if (!enemy.deleteSprite) {
		window->draw(enemy.ennemiesSprite);
	}
	for (int i = 0; i < enemiesList.size(); i++) {
		enemiesList[i].ennemiesTexture();
	}
	player.playerRender(window);
}

void InGame::enemySystemHP() {
	for (int i = 0; i < player.projos.size(); i++)
	{
		for (int j = 0; j < enemiesList.size(); j++) {
			if (enemiesList[j].ennemiesBox.contains(player.projos[i].projectileSprite.getPosition())) {
				player.projos.erase(player.projos.begin() + i);
				enemiesList[j].HP--;
			}
		}
	}

	for (int i = 0; i < enemiesList.size(); i++) {
		if (enemiesList[i].HP <= 0) {
			enemiesList.erase(enemiesList.begin() + i);
		}
	}
}