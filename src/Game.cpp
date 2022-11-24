#include "Game.h"
#include "texture.h"
#include "Player.h"

void Game() {

    Player player;

    // create the window
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);

    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        player.showTexture();

        // main loop 

        Event event;
        while (window.pollEvent(event))
        {
            // Loop event

            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        player.move();
        window.draw(player.playerSprite);
        window.display();
    }
}