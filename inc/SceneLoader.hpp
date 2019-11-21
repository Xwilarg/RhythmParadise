#pragma once

# include "Scene.hpp"
# include "InputField.hpp"

namespace rythm
{
    class SceneLoader final
    {
    public:
        SceneLoader() noexcept;
        void InvokeEvent(const sf::Event& event) noexcept;
        void Draw(sf::RenderWindow &window) const noexcept;
        void LoadGameScene();

    private:
        std::shared_ptr<InputField> _songPath;
        Scene CreateMenuScene() noexcept;
        Scene CreateGameScene() const noexcept;
        Scene _menuScene;
        Scene _gameScene;
        std::reference_wrapper<Scene> _currentScene;
    };
}