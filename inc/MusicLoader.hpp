#pragma once

#pragma comment(lib, "irrKlang.lib")

# include <irrKlang.h>
# include <string>

namespace rythm
{
    class MusicLoader final
    {
    public:
        MusicLoader() = delete;
        static void LoadMusic(const std::string& path) noexcept;

    private:
        static irrklang::ISoundEngine* _engine;
        static std::string _path;
    };
}