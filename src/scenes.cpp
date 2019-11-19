#include "scenes.hpp"
#include "InputField.hpp"

namespace rythm
{
    Scene CreateMenuScene() noexcept
    {
        Scene menu;
        menu.AddGameObject(std::make_unique<InputField>(sf::Vector2f(10.f, 10.f), sf::Vector2f(300.f, 30.f), "Song path"));
        return menu;
    }
}