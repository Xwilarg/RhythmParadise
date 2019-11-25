#pragma once

# include "AGameObject.hpp"

namespace rhythm
{
    class Rectangle final : public AGameObject
    {
    public:
        Rectangle(const sf::Vector2f& position, const sf::Vector2f& size) noexcept;
    };
}