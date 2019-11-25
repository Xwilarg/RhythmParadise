#include "MusicNote.hpp"
#include "GridSettings.hpp"

namespace rhythm
{
    MusicNote::MusicNote(const sf::Vector2f& position, std::function<void(void)>&& callback) noexcept
        : Button(position, sf::Vector2f(GridSettings::xSpacing, GridSettings::heightMusicNote), std::move(callback))
    {
        SetFillColor(sf::Color::Blue);
    }
}