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

        // Inheriting of AClickableGameObject
        void Draw(sf::RenderWindow &window) const noexcept override;

    private:
        sf::Text _hintText;
        std::string _text;
    };
}