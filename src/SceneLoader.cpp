#include "SceneLoader.hpp"
#include "InputField.hpp"
#include "Button.hpp"

namespace rythm
{
    SceneLoader::SceneLoader() noexcept
        : _menuScene(CreateMenuScene()), _gameScene(CreateGameScene()), _currentScene(_menuScene), _songPath(nullptr)
    { }

    void SceneLoader::InvokeEvent(const sf::Event& event) noexcept
    {
        _currentScene.get().InvokeEvent(event);
    }

    void SceneLoader::Draw(sf::RenderWindow &window) const noexcept
    {
        _currentScene.get().Draw(window);
    }

    void SceneLoader::LoadGameScene()
    {
        _currentScene = _gameScene;
    }

    Scene SceneLoader::CreateMenuScene() noexcept
    {
        Scene menu;
        auto songPath = std::make_shared<InputField>(sf::Vector2f(10.f, 10.f), sf::Vector2f(1000.f, 30.f), "Song path");
        _songPath = songPath;
        menu.AddGameObject(std::move(songPath));
        menu.AddGameObject(std::make_shared<Button>(sf::Vector2f(1020.f, 10.f), sf::Vector2f(30.f, 30.f), std::bind(&SceneLoader::LoadGameScene, this)));
        return menu;
    }

    Scene SceneLoader::CreateGameScene() const noexcept
    {
        Scene game;
        return game;
    }
}