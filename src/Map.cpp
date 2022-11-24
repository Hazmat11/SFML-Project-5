#include "Map.h"

Map::Map() {

}

Map::~Map() {

}

void Map::showMap()
{
	map1.loadFromFile("img/map_1.png", sf::IntRect(0, 0, 1200, 750));
	actualMap.setTexture(map1);
}