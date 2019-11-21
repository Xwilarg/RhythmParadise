#include "MusicLoader.hpp"

namespace rythm
{
    MusicLoader::~MusicLoader() noexcept
    {
        if (_music != nullptr)
        {
            _music->drop();
        }
    }

    bool MusicLoader::LoadMusic(const std::string& path) noexcept
    {
        _path = path;
        _music = _engine->play2D(_path.c_str(), false, true, true); // Is looped?, start paused?, track song?
        if (_music != nullptr)
        {
            _music->setVolume(.25f);
        }
        return _music != nullptr;
    }

    void MusicLoader::PlayMusic() noexcept
    {
        _music->setIsPaused(!_music->getIsPaused());
    }

    void MusicLoader::StopMusic() noexcept
    {
        _music->setPlayPosition(0);
        _music->setIsPaused(true);
    }

    irrklang::ISoundEngine* MusicLoader::_engine = irrklang::createIrrKlangDevice();
    irrklang::ISound* MusicLoader::_music = nullptr;
    std::string MusicLoader::_path = "";
}