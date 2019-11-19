#include "InputField.hpp"

namespace rythm
{
    InputField::InputField(const sf::Vector2f& position, const sf::Vector2f& size) noexcept
        : AClickableGameObject(position, size, sf::Color::White)
    { }
}