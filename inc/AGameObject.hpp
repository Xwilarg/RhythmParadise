#pragma once

#include <SFML/Window/Event.hpp>

namespace rythm
{
    class AGameObject
    {
    public:
        virtual ~AGameObject() = default;
        virtual void InvokeEvent(const sf::Event event) { }
    };
}