#include "KeyButton.hpp"

namespace rhythm
{
    KeyButton::KeyButton(const sf::Vector2f& position, const sf::Vector2f& size, sf::Keyboard::Key key, std::function<void(void)>&& callback) noexcept
        : AGameObject(position, size, sf::Color::White), _key(key), _callback(std::move(callback))
    { }

    void KeyButton::InvokeEvent(const sf::Event&) noexcept
    {
        if (sf::Keyboard::isKeyPressed(_key))
        {
            SetFillColor(sf::Color::Blue);
            _callback();
        }
        else
        {
            SetFillColor(sf::Color::White);
        }
    }
}