#pragma once

# include "AClickableGameObject.hpp"

namespace rythm
{
    class Scene final
    {
    public:
        void AddGameObject(std::unique_ptr<AGameObject> gameObject) noexcept;
        void InvokeEvent(const sf::Event &event) noexcept;

    private:
        std::vector<std::unique_ptr<AGameObject>> _gameObjects;
    };
}