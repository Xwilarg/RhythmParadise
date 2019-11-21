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

        // Inheriting of GameObject
        void InvokeEvent(const sf::Event& event) noexcept override;

    protected:
        virtual void OnSelect() noexcept;
        virtual void OnUnselect() noexcept;
        virtual void OnClick() noexcept;

    private:
        bool _isSelected;
    };
}