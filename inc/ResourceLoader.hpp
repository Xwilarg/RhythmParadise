#pragma once

# include <unordered_map>
# include <SFML/Graphics/Font.hpp>

namespace rythm
{
    class ResourceLoader final
    {
    public:
        ResourceLoader() = delete;
        ~ResourceLoader() noexcept;

        template <typename T>
        static const T& LoadFromFile(const std::string &path)
        {
            if (_resources.count(path) == 1)
            {
                return *reinterpret_cast<T*>(_resources[path]);
            }
            else
            {
                T* res = new T();
                if (!res->loadFromFile(path))
                    throw std::runtime_error("Invalid path " + path);
                _resources[path] = reinterpret_cast<void*>(res);
                return *res;
            }
        }

    private:
        static std::unordered_map<std::string, void*> _resources;
    };
}