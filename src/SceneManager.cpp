#include "SceneManager.h"

SceneManager::SceneManager() {
	gm.setGameManager(this->event, this->win);
}

SceneManager::~SceneManager() {

}

void SceneManager::manageScene() {
	switch (gm.index) {
	case MENU :
		menu.MenuLoop();
		break;
	case GAME :
		game.GameLoop();
		break;
	default :
		std::cout << "Error Scene !" << std::endl;
	}
}

void SceneManager::Draw() {
	switch (gm.index) {
	case MENU:
		menu.Render(gm.rw);
		break;
	case GAME:
		game.Render(gm.rw);
		break;
	default:
		std::cout << "Error Render Scene !" << std::endl;
	}
}