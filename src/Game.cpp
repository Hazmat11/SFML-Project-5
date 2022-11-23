#include "Game.h"
#include "texture.h"
#include "Player.h"

void Game() {

    DoTexture texture;
    Player gamer;

    // create the window
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);

    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        gamer.move();
        texture.showTexture();

        // main loop 

        Event event;
        while (window.pollEvent(event))
        {
            // Loop event

            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(texture.player);
        window.display();
    }
}