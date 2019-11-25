#include "Rectangle.hpp"

namespace rhythm
{
    Rectangle::Rectangle(const sf::Vector2f& position, const sf::Vector2f& size) noexcept
        : AGameObject(position, size, sf::Color::Black)
    {
        SetBorderThickness(1.f);
    }
}