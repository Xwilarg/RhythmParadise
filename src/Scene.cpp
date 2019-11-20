#include "Scene.hpp"

namespace rythm
{
    void Scene::AddGameObject(std::shared_ptr<AGameObject> gameObject) noexcept
    {
        _gameObjects.push_back(gameObject);
    }

    void Scene::InvokeEvent(const sf::Event &event) noexcept
    {
        for (auto &go : _gameObjects)
            go->InvokeEvent(event);
    }

    void Scene::Draw(sf::RenderWindow &window) const noexcept
    {
        for (auto &go : _gameObjects)
            go->Draw(window);
    }
}