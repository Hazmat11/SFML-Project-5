#include "Game.h"

void Game() {
    SceneManager sm;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        // main loop 
        sm.manageScene();

        while (window.pollEvent(event))
        {
            // Loop event
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Render(&window, sm);
    }
}

void Render(sf::RenderWindow *win, SceneManager sm) {
    win->clear();
    sm.Draw();
    win->display();
}