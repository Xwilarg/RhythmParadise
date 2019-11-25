#include "AGameObject.hpp"

namespace rhythm
{
    AGameObject::AGameObject(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color) noexcept
        : _shape(size)
    {
        _shape.setPosition(position);
		_shape.setFillColor(color);
    }

    void AGameObject::InvokeEvent(const sf::Event&) noexcept
    { }

    void AGameObject::Draw(sf::RenderWindow &window) const noexcept
    {
        window.draw(_shape);
    }

    void AGameObject::Update() noexcept
    { }

    void AGameObject::SetBorderThickness(float value) noexcept
    {
        _shape.setOutlineThickness(value);
    }

    void AGameObject::SetBorderColor(const sf::Color& color) noexcept
    {
        _shape.setOutlineColor(color);
    }

    void AGameObject::SetFillColor(const sf::Color& color) noexcept
    {
        _shape.setFillColor(color);
    }

    const sf::Vector2f& AGameObject::GetSize() const noexcept
    {
        return _shape.getSize();
    }

    const sf::Vector2f& AGameObject::GetPosition() const noexcept
    {
        return _shape.getPosition();
    }
}