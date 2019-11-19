#pragma once

# include "Scene.hpp"

namespace rythm
{
    class SceneManager final
    {
    public:
        SceneManager() noexcept;
        void InvokeEvent(const sf::Event& event) noexcept;
        void Draw(sf::RenderWindow &window) const noexcept;
        void LoadGameScene();

    private:
        Scene CreateMenuScene() noexcept;
        Scene CreateGameScene() const noexcept;
        Scene _menuScene;
        Scene _gameScene;
        Scene& _currentScene;
    };
}