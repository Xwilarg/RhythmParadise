#include "ResourceManager.hpp"

namespace rythm
{
    ResourceManager::~ResourceManager()
    {
        for (auto& elem : _resources)
            delete elem.second;
    }

    std::unordered_map<std::string, void*> ResourceManager::_resources = {};
}