#include "AGameObject.hpp"

namespace rythm
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

    const sf::Vector2f& AGameObject::GetSize() const noexcept
    {
        return _shape.getSize();
    }

    const sf::Vector2f& AGameObject::GetPosition() const noexcept
    {
        return _shape.getPosition();
    }
}