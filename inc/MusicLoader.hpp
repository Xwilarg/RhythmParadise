#pragma once

#ifdef _WIN32
#pragma comment(lib, "irrKlang.lib")
#endif

# include <irrKlang.h>
# include <string>

namespace rhythm
{
    class MusicLoader final
    {
    public:
        MusicLoader() = delete;
        ~MusicLoader() noexcept;
        static bool LoadMusic(const std::string& path) noexcept;
        static void PlayMusic() noexcept;
        static void StopMusic() noexcept;
        static void SetMusicVolume(float value) noexcept;
        // value is the position of the music between 0 and 1
        static void SetMusicPosition(float value) noexcept;
        // return a value between 0 and 1
        static float GetMusicPosition() noexcept;
        // return the number of ms elapsed
        static int GetMusicPositionIsMs() noexcept;

    private:
        static irrklang::ISoundEngine* _engine;
        static irrklang::ISound* _music;
        static std::string _path;
    };
}