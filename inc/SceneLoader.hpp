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
        void SetVolume(const std::string& value) const noexcept;
        Scene CreateMenuScene() noexcept;
        Scene CreateGameScene() const noexcept;
        std::shared_ptr<InputField> _songPath;
        Scene _menuScene;
        Scene _gameScene;
        std::reference_wrapper<Scene> _currentScene;
    };
}