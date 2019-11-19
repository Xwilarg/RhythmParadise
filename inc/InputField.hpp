#pragma once

# include <SFML/Graphics/Text.hpp>
# include "AClickableGameObject.hpp"

namespace rythm
{
    class InputField final : public AClickableGameObject
    {
    public:
        InputField(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& hintText) noexcept;

        // Inheriting of AClickableGameObject
        void OnSelect() noexcept override;
        void OnUnselect() noexcept override;

        // Inheriting of AGameObject
        void Draw(sf::RenderWindow &window) const noexcept override;
        void InvokeEvent(const sf::Event& event) noexcept override;

    private:
        sf::Text _hintText;
        sf::Text _contentText;
        sf::String _textStr;
        bool _isSelected;
    };
}