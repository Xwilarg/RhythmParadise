#include <filesystem>
#include "SceneLoader.hpp"
#include "InputField.hpp"
#include "Button.hpp"
#include "Slider.hpp"
#include "MusicLoader.hpp"

namespace rythm
{
    SceneLoader::SceneLoader() noexcept
        : _songPath(nullptr), _menuScene(CreateMenuScene()), _gameScene(CreateGameScene()), _currentScene(_menuScene)
    { }

    void SceneLoader::InvokeEvent(const sf::Event& event) noexcept
    {
        _currentScene.get().InvokeEvent(event);
    }

    void SceneLoader::Draw(sf::RenderWindow &window) const noexcept
    {
        _currentScene.get().Draw(window);
    }

    void SceneLoader::Update() noexcept
    {
        _currentScene.get().Update();
    }

    void SceneLoader::LoadGameScene()
    {
        std::string pathStr = _songPath->GetContent().toAnsiString();
        if (!std::filesystem::exists(pathStr) || !MusicLoader::LoadMusic(pathStr))
        {
            _songPath->Clear();
        }
        else
        {
            _currentScene = _gameScene;
        }
    }

    void SceneLoader::SetPositionVolume(const std::string& volumeStr) const noexcept
    {
        float value = volumeStr == "" ? 0.f : std::stoi(volumeStr) / 100.f;
        if (value < 0.f) value = 0.f;
        else if (value > 1.f) value = 1.f;
        MusicLoader::SetMusicVolume(value);
    }

    void SceneLoader::SetMusicPosition(float pos) const noexcept
    {
        MusicLoader::SetMusicPosition(pos);
    }

    Scene SceneLoader::CreateMenuScene() noexcept
    {
        Scene menu;
        _songPath = std::make_shared<InputField>(sf::Vector2f(10.f, 10.f), sf::Vector2f(1000.f, 30.f), "Song path");
        menu.AddGameObject(_songPath);
        menu.AddGameObject(std::make_shared<Button>(sf::Vector2f(1020.f, 10.f), sf::Vector2f(30.f, 30.f), std::bind(&SceneLoader::LoadGameScene, this)));
        return menu;
    }

    Scene SceneLoader::CreateGameScene() const noexcept
    {
        Scene game;

        // Music management
        game.AddGameObject(std::make_shared<Button>(sf::Vector2f(20.f, 20.f), sf::Vector2f(30.f, 30.f), MusicLoader::PlayMusic));
        game.AddGameObject(std::make_shared<Button>(sf::Vector2f(70.f, 20.f), sf::Vector2f(30.f, 30.f), MusicLoader::StopMusic));
        auto inputVolume = std::make_shared<InputField>(sf::Vector2f(120.f, 20.f), sf::Vector2f(100.f, 30.f), "Volume");
        inputVolume->SetContent("25");
        inputVolume->SetInputType(InputField::InputType::Number);
        inputVolume->SetMaxLength(3);
        inputVolume->SetOnValueChangeCallback(std::bind(&SceneLoader::SetPositionVolume, this, std::placeholders::_1));
        game.AddGameObject(std::move(inputVolume));
        auto slider = std::make_shared<Slider>(sf::Vector2f(20.f, 70.f), sf::Vector2f(100.f, 30.f));
        slider->SetValue(0.f);
        slider->SetMaxValue(1.f);
        slider->SetOnValueChangeCallback(std::bind(&SceneLoader::SetMusicPosition, this, std::placeholders::_1));
        slider->SetFollowChangeCallback(MusicLoader::GetMusicPosition);
        game.AddGameObject(std::move(slider));

        // Game grid
        game.AddGameObject(CreateVerticalGridLine(0));
        game.AddGameObject(CreateVerticalGridLine(1));
        game.AddGameObject(CreateVerticalGridLine(2));
        game.AddGameObject(CreateVerticalGridLine(3));

        return game;
    }

    std::shared_ptr<AGameObject> SceneLoader::CreateVerticalGridLine(int index) const noexcept
    {
        auto border = std::make_shared<Button>(sf::Vector2f(400.f + (index * 150.f), 20.f), sf::Vector2f(150.f, 850.f), nullptr);
        border->SetFillColor(sf::Color::Black);
        border->SetBorderThickness(1.f);
        return border;
    }
}