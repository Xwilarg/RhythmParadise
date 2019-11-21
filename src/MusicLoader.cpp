#include "MusicLoader.hpp"

namespace rythm
{
    void MusicLoader::LoadMusic(const std::string& path) noexcept
    {
        _path = std::move(path);
        _engine->play2D(_path.c_str(), true);
    }

    irrklang::ISoundEngine* MusicLoader::_engine = irrklang::createIrrKlangDevice();
    std::string MusicLoader::_path = "";
}