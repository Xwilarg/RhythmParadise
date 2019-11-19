#pragma once

# include "AClickableGameObject.hpp"

namespace rythm
{
    class InputField final : public AClickableGameObject
    {
    public:
        InputField(const sf::Vector2f& position, const sf::Vector2f& size) noexcept;
    };
}