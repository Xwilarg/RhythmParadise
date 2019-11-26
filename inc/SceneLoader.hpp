#pragma once

# include <filesystem>
# include "Scene.hpp"
# include "InputField.hpp"

namespace rhythm
{
    class SceneLoader final
    {
    public:
        SceneLoader() noexcept;
        void InvokeEvent(const sf::Event& event) noexcept;
        void Draw(sf::RenderWindow &window) const noexcept;
        void Update() noexcept;

    private:
        void LoadBeats() noexcept;
        void LoadGameSceneFromMusic(const std::filesystem::path& parentDirectory) noexcept;
        void LoadGameScene() noexcept;
        void ResetGameScene() noexcept;
        // Callback for with input field
        void SetPositionVolume(const std::string& value) const noexcept;
        // Callback with slider
        void SetMusicPosition(float pos) const noexcept;
        Scene CreateMenuScene() noexcept;
        Scene CreateGameScene() noexcept;
        std::shared_ptr<AGameObject> CreateVerticalGridLine(int index) const noexcept;
        std::shared_ptr<AGameObject> CreateKeyGridLine(int index, sf::Keyboard::Key key, std::function<void(void)>&& callback) const noexcept;
        void PressKey(int id) const noexcept;
        std::shared_ptr<InputField> _songPath;
        Scene _menuScene;
        Scene _gameScene;
        std::reference_wrapper<Scene> _currentScene;
        std::filesystem::path _currentSongDir;
    };
}