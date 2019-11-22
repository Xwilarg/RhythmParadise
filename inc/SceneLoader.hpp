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
        void Update() noexcept;
        void LoadGameScene();

    private:
        // Callback for with input field
        void SetPositionVolume(const std::string& value) const noexcept;
        // Callback with slider
        void SetMusicPosition(float pos) const noexcept;
        Scene CreateMenuScene() noexcept;
        Scene CreateGameScene() const noexcept;
        std::shared_ptr<AGameObject> CreateVerticalGridLine(int index) const noexcept;
        std::shared_ptr<InputField> _songPath;
        Scene _menuScene;
        Scene _gameScene;
        std::reference_wrapper<Scene> _currentScene;
    };
}