#pragma once

# include <functional>
# include <SFML/System/Vector2.hpp>
# include "AClickableGameObject.hpp"

namespace rythm
{
    class Button final : public AClickableGameObject
    {
    public:
        Button(const sf::Vector2f& position, const sf::Vector2f& size, std::function<void(void)>&& callback) noexcept;

    protected:
        // Inheriting of AClickableGameObject
        void OnSelect() noexcept override;
        void OnUnselect() noexcept override;

    private:
        const std::function<void(void)> _callback;
    };
}