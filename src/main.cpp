#include <SFML/Graphics.hpp>

int main()
{
    //On load la texture

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/tboros/Downloads/sans.png", sf::IntRect(0, 0, 800, 800)))
    {
        //error
    }

    //On rend la texture plus smooth

    texture.setSmooth(true);


    //On r�cup�re la taille de l'image pour scale avec la fen�tre plus tard

    int tx = texture.getSize().x;
    int ty = texture.getSize().y;

    //On cr�e une fen�tre d'affichage et limite les FPS � 60

    sf::RenderWindow window(sf::VideoMode(tx, ty), "The Binding of PikachUwU");

    window.setFramerateLimit(60);


    //On load un sprite en utilisant la texture load juste avant

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sprite.scale(sf::Vector2f(1.0f, 1.0f));




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}