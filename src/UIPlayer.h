#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class UIPlayer {
public :
	UIPlayer();
	UIPlayer(int lp); // Constructor for Life Points
	~UIPlayer();

	void updateHealth(int lp);
	void DisplayHealth(sf::RenderWindow* window);
private :
	int posx;
	int posy;

	// Life Points
	int maxLifePoints;
	int actualLP;
	std::vector<sf::Sprite> spritesLP;
	sf::Texture pokeball;
};