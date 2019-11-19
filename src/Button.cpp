#include "Button.hpp"

namespace rythm
{
    Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, std::function<void(void)> callback) noexcept
        : AClickableGameObject(position, size, sf::Color::Green), _callback(std::move(callback))
    { }

    void Button::OnSelect() noexcept
    {
        _callback();
    }

    void Button::OnUnselect() noexcept
    { }
}