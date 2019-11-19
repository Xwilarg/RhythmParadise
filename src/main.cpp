#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Rythm Hero");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
    return 0;
}