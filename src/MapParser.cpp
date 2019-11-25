#include <string>
#include "MapParser.hpp"

namespace rythm
{
    bool MapParser::LoadFile(const std::filesystem::path& path) noexcept
    {
        file.open(path);
        if (!file.is_open())
            return false;
        std::string line;
        while (std::getline(file, line))
        {
            if (line.rfind("format=", 0) == 0) { // Information about the audio format
                audioExtension = GetValue(line);
            }
        }
        return true;
    }

    const std::string& MapParser::GetAudioExtension() noexcept
    {
        return audioExtension;
    }

    std::string MapParser::GetValue(const std::string& line) noexcept
    {
        size_t pos;
        if ((pos = line.find("=")) != std::string::npos) {
            pos++;
            return line.substr(pos, line.size() - pos);
        }
        return "";
    }

    std::ifstream MapParser::file;
    std::string MapParser::audioExtension;
}