#include "Game.h"

void Game() {

    Ennemies ennemies;
    Map map;
    Player player;


    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        ennemies.ennemiesTexture();
        player.playerTexture();
        player.movePlayer();

        // main loop 

        sf::Event event;
        while (window.pollEvent(event))
        {
            // Loop event

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        player.movePlayer();
        window.draw(map.actualMap);
        window.draw(player.playerSprite);
        window.draw(ennemies.ennemiesSprite);
        window.display();
    }
}