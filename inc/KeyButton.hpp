#pragma once

# include <functional>
# include "AGameObject.hpp"

namespace rhythm
{
    // KeyButton are buttons that can only be clicked with keyboard
    class KeyButton final : public AGameObject
    {
    public:
        KeyButton(const sf::Vector2f& position, const sf::Vector2f& size, sf::Keyboard::Key key, std::function<void(void)>&& callback) noexcept;

        // Inheriting of AGameObject
        void InvokeEvent(const sf::Event& event) noexcept override;

    private:
        const sf::Keyboard::Key _key;
        const std::function<void(void)> _callback;
    };
}