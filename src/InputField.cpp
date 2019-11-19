#include "InputField.hpp"
#include "ResourceManager.hpp"

namespace rythm
{
    InputField::InputField(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& hintText) noexcept
        : AClickableGameObject(position, size, sf::Color::White), _hintText(hintText, ResourceManager::LoadFromFile<sf::Font>("fonts/Louis George Cafe.ttf"), static_cast<int>(size.y) - 10)
    {
        _hintText.setFillColor(sf::Color(127, 127, 127));
        _hintText.setPosition(sf::Vector2f(position.x + 5.f, position.y));
        SetBorderThickness(2.f);
    }

    void InputField::OnSelect() noexcept
    {
        SetBorderColor(sf::Color(60, 143, 252)); // Blue
    }

    void InputField::OnUnselect() noexcept
    {
        SetBorderColor(sf::Color::White);
    }

    void InputField::Draw(sf::RenderWindow &window) const noexcept
    {
        AClickableGameObject::Draw(window);
        if (_text.empty())
        {
            window.draw(_hintText);
        }
    }
}