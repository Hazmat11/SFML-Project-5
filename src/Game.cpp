#include "Game.h"

void Game() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE, sf::Style::Fullscreen);
    window->setFramerateLimit(60);
    SceneManager sm(window);
    while (window->isOpen())
    {
        sf::Event event;
        // main loop 
        sm.manageScene(&event);

        while (window->pollEvent(event))
        {
            // Loop event
            
            if (event.type == sf::Event::Closed)
                window->close();
        }
        sm.SetGameManager(&event);
        Render(window, sm);
    }
}

void Render(sf::RenderWindow *win, SceneManager sm) {
    win->clear();
    sm.Draw();
    win->display();
}