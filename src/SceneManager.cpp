#include "SceneManager.hpp"
#include "InputField.hpp"
#include "Button.hpp"

namespace rythm
{
    SceneManager::SceneManager() noexcept
        : _menuScene(CreateMenuScene()), _gameScene(CreateGameScene()), _currentScene(_menuScene)
    { }

    void SceneManager::InvokeEvent(const sf::Event& event) noexcept
    {
        _currentScene.InvokeEvent(event);
    }

    void SceneManager::Draw(sf::RenderWindow &window) const noexcept
    {
        _currentScene.Draw(window);
    }

    void SceneManager::LoadGameScene()
    {
        _currentScene = _gameScene;
    }

    Scene SceneManager::CreateMenuScene() noexcept
    {
        Scene menu;
        menu.AddGameObject(std::make_unique<InputField>(sf::Vector2f(10.f, 10.f), sf::Vector2f(300.f, 30.f), "Song path"));
        menu.AddGameObject(std::make_unique<Button>(sf::Vector2f(10.f, 320.f), sf::Vector2f(30.f, 30.f), std::bind(&SceneManager::LoadGameScene, this)));
        return menu;
    }

    Scene SceneManager::CreateGameScene() const noexcept
    {
        Scene game;
        return game;
    }
}