#pragma once

# include <fstream>
# include <filesystem>

namespace rythm
{
    class MapParser final
    {
    public:
        static bool LoadFile(const std::filesystem::path& path) noexcept;
        static const std::string& GetAudioExtension() noexcept;

    private:
        static std::string GetValue(const std::string& line) noexcept;
        static std::ifstream file;
        static std::string audioExtension; // Extension of the music file
    };
}