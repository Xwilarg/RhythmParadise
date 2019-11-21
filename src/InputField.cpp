#include <SFML/Window/Clipboard.hpp>
#include "InputField.hpp"
#include "ResourceLoader.hpp"

namespace rythm
{
    InputField::InputField(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& hintText) noexcept
        : AClickableGameObject(position, size, sf::Color::White), _hintText(hintText, ResourceLoader::LoadFromFile<sf::Font>("fonts/Louis George Cafe.ttf"), static_cast<int>(size.y) - 10),
        _contentText("", ResourceLoader::LoadFromFile<sf::Font>("fonts/Louis George Cafe.ttf"), static_cast<int>(size.y) - 10), _textStr(""), _isSelected(false),
        _inputType(InputType::Any), _maxLength(-1), _onValueChange(nullptr)
    {
        _hintText.setFillColor(sf::Color(127, 127, 127));
        _hintText.setPosition(sf::Vector2f(position.x + 5.f, position.y));
        _contentText.setFillColor(sf::Color::Black);
        _contentText.setPosition(sf::Vector2f(position.x + 5.f, position.y));
        SetBorderThickness(2.f);
    }

    void InputField::Clear() noexcept
    {
        _textStr.clear();
        _contentText.setString(_textStr);
    }

    const sf::String& InputField::GetContent() const noexcept
    {
        return _textStr;
    }

    void InputField::SetContent(const sf::String& value) noexcept
    {
        _textStr = value;
         _contentText.setString(_textStr);
    }

    void InputField::SetInputType(InputType value) noexcept
    {
        _inputType = value;
    }

    void InputField::SetMaxLength(int value) noexcept
    {
        _maxLength = value;
    }

    void InputField::SetOnValueChangeCallback(std::function<void(const std::string&)>&& callback) noexcept
    {
        _onValueChange = callback;
    }

    void InputField::OnSelect() noexcept
    {
        SetBorderColor(sf::Color(60, 143, 252)); // Blue
        _isSelected = true;
    }

    void InputField::OnUnselect() noexcept
    {
        SetBorderColor(sf::Color::White);
        _isSelected = false;
    }

    void InputField::Draw(sf::RenderWindow &window) const noexcept
    {
        AClickableGameObject::Draw(window);
        if (_textStr.isEmpty())
        {
            window.draw(_hintText);
        }
        else
        {
            window.draw(_contentText);
        }
    }

    void InputField::InvokeEvent(const sf::Event& event) noexcept
    {
        AClickableGameObject::InvokeEvent(event);
        if (_isSelected)
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace)
            {
                size_t size = _textStr.getSize();
                if (size > 0)
                {
                    _textStr = _textStr.substring(0, size - 1);
                    _contentText.setString(_textStr);
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::V)
            {
                _textStr += sf::Clipboard::getString();
                _textStr.replace("\n", "");
                _contentText.setString(_textStr);
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                _textStr = "";
                _contentText.setString("");
            }
            else if (event.type == sf::Event::TextEntered && event.text.unicode != 8)
            {
                if (_inputType == InputType::Any ||
                (_inputType == InputType::Number && event.text.unicode >= '0' && event.text.unicode <= '9'))
                _textStr += event.text.unicode;
                _contentText.setString(_textStr);
            }
            if (_maxLength != -1 && _textStr.getSize() > _maxLength)
            {
                _textStr = _textStr.substring(0, _maxLength);
                _contentText.setString(_textStr);
            }
            if (_onValueChange != nullptr)
            {
                _onValueChange(_textStr.toAnsiString());
            }
        }
    }
}