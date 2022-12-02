#include "InGame.h"

InGame::InGame() {
	enemy.setEnemy(&player);
	enemiesList.push_back(enemy);
	map = new Map(&player);
}

InGame::~InGame() {

}

//Manage the collision between projectiles and enemies
void InGame::projCollision() {
	for (int i = 0; i < player.projos.size(); i++)
	{
		if (enemiesList[i].ennemiesBox.contains(player.projos[i].projectileSprite.getPosition())) {
			player.projos.erase(player.projos.begin() + i);

			if (!enemiesList[i].buffer.loadFromFile(JIGGLYPUFF_HURT_SOUND_PATH)) {
				std::cout << "-1";
			}
			enemiesList[i].jigglyoofSound.setBuffer(enemiesList[i].buffer);
			enemiesList[i].jigglyoofSound.setVolume(25);
			enemiesList[i].jigglyoofSound.play();
			enemiesList[i].HP--;
		}
	}

	for (int i = 0; i < enemiesList.size(); i++) {
		if (enemiesList[i].systemHP()) {
			enemiesList.erase(enemiesList.begin() + i);
		}
	}
}

//Update loop for every gameplay elements
void InGame::GameLoop(sf::RenderWindow* win) {
	player.playerLoop(win);
	for (int i = 0; i < enemiesList.size(); i++) {
		enemiesList[i].ennemiesLoop();
	}
	map->mapLoop();
	enemySystemHP();
}

//Update loop for every rendered elements
void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map->actualMap);
	if (!map->deleteSprite) {
		window->draw(map->object);
		window->draw(map->keySprite);
	}
	for (int i = 0; i < enemiesList.size(); i++) {
		if (!enemiesList[i].deleteSprite) {
			window->draw(enemiesList[i].ennemiesSprite);
		}
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