#pragma once

# include "AClickableGameObject.hpp"

namespace rythm
{
    class Slider final : public AClickableGameObject
    {
    public:
        Slider(const sf::Vector2f& position, const sf::Vector2f& size) noexcept;
        void SetValue(float value) noexcept;
        void SetMaxValue(float value) noexcept;

        // Inheriting of AClickableGameObject
        void OnClick(const sf::Vector2i& pos) noexcept override;

        // Inheriting of AGameObject
        void Draw(sf::RenderWindow &window) const noexcept override;

    private:
        sf::RectangleShape _fillShape; // The rectangle representing the loading    
        float _maxValue;
        float _value;
    };
}