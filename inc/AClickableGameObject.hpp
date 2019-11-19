#pragma once

# include <memory>
# include "AGameObject.hpp"

namespace rythm
{
    class AClickableGameObject : public AGameObject
    {
    public:
		AClickableGameObject(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color) noexcept;
        virtual ~AClickableGameObject() noexcept = default;
        virtual void OnSelect() noexcept = 0;
        virtual void OnUnselect() noexcept = 0;

        // Inheriting of GameObject
        void InvokeEvent(const sf::Event& event) noexcept override;

    private:
        bool _isSelected;
    };
}