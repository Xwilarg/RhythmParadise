#pragma once

# include <fstream>
# include <filesystem>
# include "Beat.hpp"

namespace rhythm
{
    class MapParser final
    {
    public:
        static bool LoadFile(const std::filesystem::path& path) noexcept;
        static const std::string& GetAudioExtension() noexcept;
        static const std::vector<rhythm::Beat> GetAllBeats() noexcept;

    private:
        static std::string GetFieldValue(const std::string& line) noexcept;
        static Beat GetBeatValue(const std::string &line) noexcept;
        enum ParsingType
        {
            Field,
            Beat
        };
        static std::string _audioExtension; // Extension of the music file
        static std::vector<rhythm::Beat> _beats;
    };
}