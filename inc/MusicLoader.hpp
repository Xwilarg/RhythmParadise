#pragma once

# include <SFML/Audio/Music.hpp>

namespace rythm
{
    class MusicLoader final
    {
    public:
        MusicLoader() = delete;
        static bool LoadMusic(const std::string& path) noexcept;

    private:
        static sf::Music _music;
    };
}