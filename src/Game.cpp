#include "Game.h"
#include "Player.h"
#include "Map.h"

void Game() {

    Map map;
    Player player;

    // create the window
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);

    player.arrangeSprite();
    player.setPlayerCollisions();


    //map.showMap();

    map.showMap();

    while (window.isOpen())
    {
        player.showTexture();
        player.movePlayer();


        // main loop u

        Event event;
        while (window.pollEvent(event))
        {
            // Loop event

            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        player.movePlayer();
        window.draw(map.actualMap);
        window.draw(player.playerSprite);
        window.display();
    }
}