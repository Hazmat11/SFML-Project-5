#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include "SceneManager.h"


#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define TITLE std::string("The Binding of Pikachu")

void Game();
void Render(sf::RenderWindow*, SceneManager sm);