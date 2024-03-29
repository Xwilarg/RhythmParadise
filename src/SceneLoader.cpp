#include <fstream>
#include "GridSettings.hpp"
#include "MusicLoader.hpp"
#include "SceneLoader.hpp"
#include "InputField.hpp"
#include "Rectangle.hpp"
#include "KeyButton.hpp"
#include "MapParser.hpp"
#include "MusicNote.hpp"
#include "Button.hpp"
#include "Slider.hpp"

namespace rhythm
{
    using gs = GridSettings;

    SceneLoader::SceneLoader() noexcept
        : _songPath(nullptr), _menuScene(CreateMenuScene()), _gameScene(CreateGameScene()), _currentScene(_menuScene), _currentSongDir()
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

    void SceneLoader::LoadBeats() noexcept
    {
        for (const auto& beat : MapParser::GetAllBeats())
        {
            _gameScene.AddGameObject(std::make_shared<MusicNote>(sf::Vector2f(
                gs::xPos + ((beat.line - 1) * gs::xSpacing),
                gs::yNoteReceiver - beat.ms
            ), nullptr));
        }
    }

    void SceneLoader::LoadGameSceneFromMusic(const std::filesystem::path& parentDirectory) noexcept // Load the game from a previously created map
    {
        if (!MapParser::LoadFile(parentDirectory / "map.rtm") ||
            !MusicLoader::LoadMusic(parentDirectory.string() + "/audio." + MapParser::GetAudioExtension()))
        { }
        else
        {
            LoadBeats();
            _currentSongDir = parentDirectory;
            _currentScene = _gameScene;
        }
    }

    void SceneLoader::LoadGameScene() noexcept // Load the game from a music name
    {
        std::filesystem::path path(_songPath->GetContent().toAnsiString()); // Path to the song selected by the player
        std::filesystem::path finalPath("maps/" + path.stem().string()); // New folder created in the musics/ folder
        std::string extension(path.extension().string()); // Extension of the music file
        std::string finalFile(finalPath.string() + "/audio" + extension); // New filename of the audio
        if (!std::filesystem::exists(path) ||
            !MusicLoader::LoadMusic(path.string()) ||
            !std::filesystem::create_directory(finalPath) ||
            !std::filesystem::copy_file(path, finalFile) ||
            !MusicLoader::LoadMusic(finalFile))
        {
            _songPath->Clear();
        }
        else
        {
            std::ofstream map(finalPath / "map.rtm");
            map << "format=" << extension.substr(1, extension.size()) << "\n\n";
            map << "[Beats]\n";
            map.close();
            _currentSongDir = finalPath;
            _currentScene = _gameScene;
        }
    }

    void SceneLoader::ResetGameScene() noexcept
    {
        _gameScene = CreateGameScene();
        MapParser::LoadFile(_currentSongDir / "map.rtm");
        LoadBeats();
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
        if (!std::filesystem::exists("maps"))
            std::filesystem::create_directory("maps");

        Scene menu;
        _songPath = std::make_shared<InputField>(sf::Vector2f(10.f, 10.f), sf::Vector2f(1000.f, 30.f), "Song path");
        _songPath->Click();
        menu.AddGameObject(_songPath);
        auto validate = std::make_shared<Button>(sf::Vector2f(1020.f, 10.f), sf::Vector2f(30.f, 30.f), std::bind(&SceneLoader::LoadGameScene, this));
        validate->SetKeyClick(sf::Keyboard::Return);
        menu.AddGameObject(std::move(validate));
        int index = 0;
        for (const auto& directory : std::filesystem::directory_iterator("maps")) // Gettings maps from maps/ folder
        {
            if (!std::filesystem::is_directory(directory)) // We ignore files
                continue;
            auto songSelection = std::make_shared<Button>(sf::Vector2f(10.f, 80.f + (50.f * index)), sf::Vector2f(500.f, 30.f), std::bind(&SceneLoader::LoadGameSceneFromMusic, this, directory));
            songSelection->SetFillColor(sf::Color::Black);
            songSelection->SetBorderThickness(1.f);
            songSelection->SetBorderColor(sf::Color::White);
            songSelection->SetText(directory.path().filename().string());
            menu.AddGameObject(songSelection);
            index++;
        }
        return menu;
    }

    Scene SceneLoader::CreateGameScene() noexcept
    {
        Scene game;

        // Music management
        auto play = std::make_shared<Button>(sf::Vector2f(20.f, 20.f), sf::Vector2f(30.f, 30.f), MusicLoader::PlayMusic);
        play->SetKeyClick(sf::Keyboard::Space);
        game.AddGameObject(std::move(play));
        auto stop = std::make_shared<Button>(sf::Vector2f(70.f, 20.f), sf::Vector2f(30.f, 30.f), MusicLoader::StopMusic);
        stop->SetKeyClick(sf::Keyboard::Escape);
        game.AddGameObject(std::move(stop));
        auto inputVolume = std::make_shared<InputField>(sf::Vector2f(120.f, 20.f), sf::Vector2f(100.f, 30.f), "Volume"); // InputField for volume (between 0 and 1)
        inputVolume->SetContent("25");
        inputVolume->SetInputType(InputField::InputType::NUMBER);
        inputVolume->SetMaxLength(3);
        inputVolume->SetOnValueChangeCallback(std::bind(&SceneLoader::SetPositionVolume, this, std::placeholders::_1));
        game.AddGameObject(std::move(inputVolume));
        auto speedMultiplicator = std::make_shared<InputField>(sf::Vector2f(240.f, 20.f), sf::Vector2f(45.f, 30.f), "Spd"); // InputField for music speed multiplicator
        speedMultiplicator->SetContent("1");
        speedMultiplicator->SetInputType(InputField::InputType::NUMBER);
        speedMultiplicator->SetMaxLength(3);
        game.AddGameObject(std::move(speedMultiplicator));
        auto slider = std::make_shared<Slider>(sf::Vector2f(20.f, 70.f), sf::Vector2f(100.f, 30.f)); // Slider for music progression
        slider->SetValue(0.f);
        slider->SetMaxValue(1.f);
        slider->SetOnValueChangeCallback(std::bind(&SceneLoader::SetMusicPosition, this, std::placeholders::_1));
        slider->SetFollowChangeCallback(MusicLoader::GetMusicPosition);
        game.AddGameObject(std::move(slider));
        auto reset = std::make_shared<Button>(sf::Vector2f(20.f, 120.f), sf::Vector2f(30.f, 30.f), std::bind(&SceneLoader::ResetGameScene, this));
        reset->SetKeyClick(sf::Keyboard::R);
        game.AddGameObject(std::move(reset));

        // Game grid
        game.AddGameObject(CreateVerticalGridLine(0));
        game.AddGameObject(CreateVerticalGridLine(1));
        game.AddGameObject(CreateVerticalGridLine(2));
        game.AddGameObject(CreateVerticalGridLine(3));
        game.AddGameObject(CreateKeyGridLine(0, sf::Keyboard::Key::D, std::bind(&SceneLoader::PressKey, this, 0)));
        game.AddGameObject(CreateKeyGridLine(1, sf::Keyboard::Key::F, std::bind(&SceneLoader::PressKey, this, 1)));
        game.AddGameObject(CreateKeyGridLine(2, sf::Keyboard::Key::J, std::bind(&SceneLoader::PressKey, this, 2)));
        game.AddGameObject(CreateKeyGridLine(3, sf::Keyboard::Key::K, std::bind(&SceneLoader::PressKey, this, 3)));

        return game;
    }

    std::shared_ptr<AGameObject> SceneLoader::CreateVerticalGridLine(int index) const noexcept
    {
        return std::make_shared<Rectangle>(sf::Vector2f(gs::xPos + (index * gs::xSpacing), gs::yPos), sf::Vector2f(gs::xSpacing, gs::height));
    }

    std::shared_ptr<AGameObject> SceneLoader::CreateKeyGridLine(int index, sf::Keyboard::Key key, std::function<void(void)>&& callback) const noexcept
    {
        return std::make_shared<KeyButton>(sf::Vector2f(gs::xPos + (index * gs::xSpacing), gs::yNoteReceiver), sf::Vector2f(gs::xSpacing, gs::heightNoteReceiver), key, std::move(callback));
    }

    void SceneLoader::PressKey(int id) const noexcept
    {
        (void)id;
    }
}