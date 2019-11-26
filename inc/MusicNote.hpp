#pragma once

# include <functional>
# include "Button.hpp"

namespace rhythm
{
    class MusicNote final : public Button
    {
    public:
        MusicNote(const sf::Vector2f& position, std::function<void(void)>&& callback) noexcept;

        // Inheriting of AGameObject
        void Update() noexcept override;

    private:
        float _initialYPos; // Keep memory of initial Y pos to calculate current pos from it
    };
}