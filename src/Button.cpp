#include "Button.hpp"

namespace rythm
{
    Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, std::function<void(void)>&& callback) noexcept
        : AClickableGameObject(position, size, sf::Color::Green), _callback(std::move(callback)), _key((sf::Keyboard::Key)-1)
    { }

    void Button::SetKeyClick(sf::Keyboard::Key key) noexcept
    {
        _key = key;
    }

    void Button::InvokeEvent(const sf::Event& event) noexcept
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == _key)
        {
            OnClick(sf::Vector2i(0, 0));
        }
    }

    void Button::OnClick(const sf::Vector2i&) noexcept
    {
        _callback();
    }
}