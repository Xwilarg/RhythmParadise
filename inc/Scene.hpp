#pragma once

# include "AClickableGameObject.hpp"

namespace rythm
{
    class Scene final
    {
    public:
        void AddGameObject(std::shared_ptr<AGameObject>&& gameObject) noexcept;
        void InvokeEvent(const sf::Event &event) noexcept;
        void Draw(sf::RenderWindow &window) const noexcept;
        void Update() noexcept;

    private:
        std::vector<std::shared_ptr<AGameObject>> _gameObjects;
    };
}