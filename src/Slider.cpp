#include "Slider.hpp"

namespace rythm
{
    Slider::Slider(const sf::Vector2f& position, const sf::Vector2f& size) noexcept
        : AClickableGameObject(position, size, sf::Color::White), _fillShape(size),
        _maxValue(100), _value(100)
    {
        _fillShape.setPosition(position);
		_fillShape.setFillColor(sf::Color::Green);
    }

    void Slider::SetValue(float value) noexcept
    {
        _value = value;
        if (_value > _maxValue)
        {
            _value = _maxValue;
        }
        auto size = GetSize();
        _fillShape.setSize(sf::Vector2f(_value * size.x / _maxValue, size.y));
    }

    void Slider::SetMaxValue(float value) noexcept
    {
        _maxValue = value;
        SetValue(_value);
    }

    void Slider::OnClick(const sf::Vector2i& pos) noexcept
    {
        SetValue(pos.x * _maxValue / GetSize().x);
    }

    void Slider::Draw(sf::RenderWindow &window) const noexcept
    {
        AClickableGameObject::Draw(window);
        window.draw(_fillShape);
    }
}