#include "MusicLoader.hpp"

namespace rythm
{
    void MusicLoader::LoadMusic(std::string&& path) noexcept
    {
        _path = std::move(path);
    }

    irrklang::ISoundEngine* MusicLoader::_engine = irrklang::createIrrKlangDevice();
    std::string MusicLoader::_path = "";
}