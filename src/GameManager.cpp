#include "GameManager.h"

GameManager::GameManager() {
}

GameManager::~GameManager() {

}

void GameManager::setGameManager(sf::Event* ev, sf::RenderWindow* renderW) {
	this->index = 1;
	this->e = ev;
	this->rw = renderW;
}