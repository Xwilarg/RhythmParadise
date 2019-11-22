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
        // Emulate on a click on this object
        void Click() noexcept;

        // Inheriting of GameObject
        void InvokeEvent(const sf::Event& event) noexcept override;

    protected:
        virtual void OnSelect() noexcept;
        virtual void OnUnselect() noexcept;
        // pos is the position of the click on the object
        virtual void OnClick(const sf::Vector2i& pos) noexcept;

    private:
        bool _isSelected;
    };
}