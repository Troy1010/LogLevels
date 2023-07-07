#pragma once

/**
* These are my favorite logging levels:
    logz
        Easy, temporary, local debugging. Should not be merged into releases.
    Info
        Important milestones that are always good to see, like user clicks, initialization complete, etc. Use sparingly.
    Error
        Something went wrong. Having this separate from "Info" is what allows it to have extra flare, like red highlighting and such in some IDEs.
    Warning
        Something might be wrong. Having this separate from "Info" is what allows it to have extra flare, like yellow highlighting and such in some IDEs.
    Debug
        Allows you to commit useful logs without having to see them unless you want to.
    Verbose
        For long messages.
    Flooding
        For messages that might write to the log every frame.

I generally like to keep the log level at WARNING, and freely use logz while developing. Then, before release, delete or change all logz to whatever makes sense. That way, I can see very accommodating logs while developing.. and if I come back later, I can see those old logs by setting the log level to DEBUG or VERBOSE.. but otherwise, they're hidden.
 */
struct LogLevel
{
    enum Enum
    {
        ALWAYS,
        NONE,
        INFO,
        // Ends with "Z" because otherwise it's seen as the ERROR macro
        ERRORZ,
        WARNING,
        // Ends with "Z" because otherwise it's seen as the DEBUG macro
        DEBUGZ,
        VERBOSE,
        FLOODING
    };
};
