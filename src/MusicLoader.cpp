#include "MusicLoader.hpp"

namespace rythm
{
    bool MusicLoader::LoadMusic(const std::string& path) noexcept
    {
        return _music.openFromFile(path);
    }

    sf::Music MusicLoader::_music;
}