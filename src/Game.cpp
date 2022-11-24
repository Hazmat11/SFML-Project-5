#include "Game.h"
#include "texture.h"
#include "Player.h"
#include "Map.h"

void Game() {

    Map map;
    Player player;

    // create the window
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);

    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    player.arrangeSprite();
    player.setPlayerCollisions();
    //map.showMap();

    while (window.isOpen())
    {
        player.showTexture();
        player.movePlayer();

        // main loop 

        Event event;
        while (window.pollEvent(event))
        {
            // Loop event

            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        player.movePlayer();
        window.draw(player.playerSprite);
        window.draw(map.actualMap);
        window.display();
    }
}