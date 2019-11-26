#include <sstream>
#include <string>
#include "MapParser.hpp"

namespace rhythm
{
    bool MapParser::LoadFile(const std::filesystem::path& path) noexcept
    {
        _beats.clear();
        std::ifstream file(path);
        if (!file.is_open())
            return false;
        std::string line;
        ParsingType _type = ParsingType::Field;
        while (std::getline(file, line))
        {
            if (line.rfind("[Beats]", 0) == 0) { // Begin information about beats
                _type = ParsingType::Beat;
            }
            else if (_type == ParsingType::Field)
            {
                if (line.rfind("format=", 0) == 0) { // Information about the audio format
                    _audioExtension = GetFieldValue(line);
                }
            }
            else if (_type == ParsingType::Beat)
            {
                _beats.push_back(GetBeatValue(line));
            }
        }
        file.close();
        return true;
    }

    const std::string& MapParser::GetAudioExtension() noexcept
    {
        return _audioExtension;
    }

    const std::vector<rhythm::Beat> MapParser::GetAllBeats() noexcept
    {
        return _beats;
    }

    std::string MapParser::GetFieldValue(const std::string& line) noexcept
    {
        size_t pos;
        if ((pos = line.find("=")) != std::string::npos) {
            pos++;
            return line.substr(pos, line.size() - pos);
        }
        return "";
    }

    Beat MapParser::GetBeatValue(const std::string& line) noexcept
    {
        std::stringstream stream(line);
        rhythm::Beat b;
        stream >> b.line >> b.ms;
        return b;
    }

    std::string MapParser::_audioExtension;
    std::vector<Beat> MapParser::_beats;
}