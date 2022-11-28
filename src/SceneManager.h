#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "GameManager.h"
#include "InGame.h"
#include "Menu.h"

#define MENU 0
#define GAME 1

class SceneManager {
public :
	sf::RenderWindow* rWin;

	SceneManager();
	SceneManager(sf::RenderWindow* win);
	~SceneManager();

	void SetGameManager(sf::Event* event);
	void manageScene(sf::Event* event);
	void Draw();

private :
	Menu* menu;
	InGame game;
	GameManager gm;
};
