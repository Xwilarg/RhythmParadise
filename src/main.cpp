#include "SceneLoader.hpp"

int main()
{
    rhythm::SceneLoader scene;
    sf::RenderWindow window(sf::VideoMode(1600, 900), "rhythm Hero");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            scene.InvokeEvent(event);
        }
        window.clear();
        scene.Update();
        scene.Draw(window);
        window.display();
    }
    return 0;
}