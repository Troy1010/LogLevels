#pragma once

struct LogLevel
{
    enum Enum
    {
        ALWAYS,
        NONE,
        INFO,
        ERRORZ,
        // Ends with "Z" because otherwise it's seen as the ERROR macro
        WARNING,
        DEBUGZ,
        // Ends with "Z" because otherwise it's seen as the DEBUG macro
        VERBOSE
    };
};
