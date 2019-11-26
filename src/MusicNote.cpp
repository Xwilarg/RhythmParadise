#include "MusicNote.hpp"
#include "MusicLoader.hpp"
#include "GridSettings.hpp"

namespace rhythm
{
    MusicNote::MusicNote(const sf::Vector2f& position, std::function<void(void)>&& callback) noexcept
        : Button(position, sf::Vector2f(GridSettings::xSpacing, GridSettings::heightMusicNote), std::move(callback)),
        _initialYPos(position.y)
    {
        SetFillColor(sf::Color::Blue);
    }

    void MusicNote::Update() noexcept
    {
        const auto& position = GetPosition();
        SetPosition(sf::Vector2f(position.x, _initialYPos + MusicLoader::GetMusicPositionIsMs()));
    }
}