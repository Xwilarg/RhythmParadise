#pragma once

# include <SFML/Graphics/RectangleShape.hpp>
# include <memory>
# include "AGameObject.hpp"

namespace rythm
{
    class AClickableGameObject : public AGameObject
    {
    public:
        virtual ~AClickableGameObject();
        void CheckClick(sf::Vector2i mousePos);
        virtual void OnClick() = 0;

    private:
        sf::RectangleShape _shape;
    };
}