#pragma once

namespace rythm
{
    struct Beat final
    {
        int line; // Line in which the beat is falling
        int ms; // Duration in ms before the line reach the player
    };
}