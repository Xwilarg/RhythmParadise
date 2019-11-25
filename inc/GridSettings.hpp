#pragma once

namespace rhythm
{
    struct GridSettings final // Constants about the in-game grid
    {
        static constexpr float xPos = 400.f;
        static constexpr float yPos = 20.f;
        static constexpr float xSpacing = 150.f; // Space between 2 column
        static constexpr float height = 850.f;
        // NoteReceiver if the thing controlled by the player
        static constexpr float yNoteReceiver = 825.f;
        static constexpr float heightNoteReceiver = 2.f;
    };
}