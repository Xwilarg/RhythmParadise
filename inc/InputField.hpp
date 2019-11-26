#pragma once

# include <SFML/Graphics/Text.hpp>
# include <functional>
# include "AClickableGameObject.hpp"

namespace rhythm
{
    class InputField final : public AClickableGameObject
    {
    public:
        enum InputType
        {
            ANY,
            NUMBER
        };
        InputField(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& hintText) noexcept;
        void Clear() noexcept;
        const sf::String& GetContent() const noexcept;
        void SetContent(const sf::String& value) noexcept;
        void SetInputType(InputType value) noexcept;
        void SetMaxLength(int value) noexcept;
        void SetOnValueChangeCallback(std::function<void(const std::string&)>&& callback) noexcept;

        // Inheriting of AGameObject
        void Draw(sf::RenderWindow &window) const noexcept override;
        void InvokeEvent(const sf::Event& event) noexcept override;

    protected:
        // Inheriting of AClickableGameObject
        void OnSelect() noexcept override;
        void OnUnselect() noexcept override;

    private:
        sf::Text _hintText;
        sf::Text _contentText;
        sf::String _textStr;
        bool _isSelected;
        InputType _inputType; // What kind of input the input field can receive
        int _maxLength; // Max number of character, -1 to disable
        std::function<void(const std::string&)> _onValueChange;
    };
}