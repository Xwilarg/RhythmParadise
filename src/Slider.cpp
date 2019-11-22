#include "Slider.hpp"

namespace rythm
{
    Slider::Slider(const sf::Vector2f& position, const sf::Vector2f& size) noexcept
        : AClickableGameObject(position, size, sf::Color::White), _fillShape(size),
        _maxValue(100), _value(100), _onValueChange(nullptr)
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

    void Slider::SetOnValueChangeCallback(std::function<void(float)>&& callback) noexcept
    {
        _onValueChange = callback;
    }

    void Slider::SetFollowChangeCallback(std::function<float(void)>&& callback) noexcept
    {
        _followChange = callback;
    }

    void Slider::OnClick(const sf::Vector2i& pos) noexcept
    {
        SetValue(pos.x * _maxValue / GetSize().x);
        if (_onValueChange != nullptr)
        {
            _onValueChange(_value);
        }
    }

    void Slider::Draw(sf::RenderWindow &window) const noexcept
    {
        AClickableGameObject::Draw(window);
        window.draw(_fillShape);
    }

    void Slider::Update() noexcept
    {
        SetValue(_followChange());
    }
}