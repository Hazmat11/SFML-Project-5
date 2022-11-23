#include <SFML/Graphics.hpp>
#include "texture.h"

int main()
{
    DoTexture texture;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);

    texture.showTexture();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(texture.sprite);
        window.display();
    }

    return 0;
}