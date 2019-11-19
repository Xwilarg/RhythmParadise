#include "ResourceLoader.hpp"

namespace rythm
{
    ResourceLoader::~ResourceLoader()
    {
        for (auto& elem : _resources)
            delete elem.second;
    }

    std::unordered_map<std::string, void*> ResourceLoader::_resources = {};
}