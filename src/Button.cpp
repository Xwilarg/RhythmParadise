#include "Button.hpp"
#include "ResourceLoader.hpp"

namespace rythm
{
    Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, std::function<void(void)>&& callback) noexcept
        : AClickableGameObject(position, size, sf::Color::Green), _callback(std::move(callback)), _key((sf::Keyboard::Key)-1),
        _contentText("", ResourceLoader::LoadFromFile<sf::Font>("fonts/Louis George Cafe.ttf"), static_cast<int>(size.y) - 10)
    {
        _contentText.setPosition(sf::Vector2f(position.x + 5.f, position.y));
    }

    void Button::SetKeyClick(sf::Keyboard::Key key) noexcept
    {
        _key = key;
    }

    void Button::SetText(const sf::String& text) noexcept
    {
        _contentText.setString(text);
    }

    void Button::Draw(sf::RenderWindow &window) const noexcept
    {
        AClickableGameObject::Draw(window);
        window.draw(_contentText);
    }

    void Button::InvokeEvent(const sf::Event& event) noexcept
    {
        AClickableGameObject::InvokeEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == _key)
        {
            OnClick(sf::Vector2i(0, 0));
        }
    }

    void Button::OnClick(const sf::Vector2i&) noexcept
    {
        _callback();
    }
}