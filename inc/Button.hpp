#pragma once

# include <functional>
# include <SFML/Graphics/Text.hpp>
# include "AClickableGameObject.hpp"

namespace rythm
{
    class Button final : public AClickableGameObject
    {
    public:
        Button(const sf::Vector2f& position, const sf::Vector2f& size, std::function<void(void)>&& callback) noexcept;
        void SetKeyClick(sf::Keyboard::Key key) noexcept;
        void SetText(const sf::String& text) noexcept;

        // Inheriting of AGameObject
        void Draw(sf::RenderWindow &window) const noexcept override;
        void InvokeEvent(const sf::Event& event) noexcept override;

    protected:
        // Inheriting of AClickableGameObject
        void OnClick(const sf::Vector2i& pos) noexcept override;

    private:
        const std::function<void(void)> _callback;
        sf::Keyboard::Key _key;
        sf::Text _contentText;
    };
}