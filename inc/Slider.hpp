#pragma once

# include <functional>
# include "AClickableGameObject.hpp"

namespace rhythm
{
    class Slider final : public AClickableGameObject
    {
    public:
        Slider(const sf::Vector2f& position, const sf::Vector2f& size) noexcept;
        void SetValue(float value) noexcept;
        void SetMaxValue(float value) noexcept;
        void SetOnValueChangeCallback(std::function<void(float)>&& callback) noexcept;
        void SetFollowChangeCallback(std::function<float(void)>&& bacllback) noexcept;

        // Inheriting of AClickableGameObject
        void OnClick(const sf::Vector2i& pos) noexcept override;

        // Inheriting of AGameObject
        void Draw(sf::RenderWindow &window) const noexcept override;
        void Update() noexcept;

    private:
        sf::RectangleShape _fillShape; // The rectangle representing the loading    
        float _maxValue;
        float _value;
        std::function<void(float)> _onValueChange;
        // Callback so the value of the slider follow the one of the function
        std::function<float(void)> _followChange;
    };
}