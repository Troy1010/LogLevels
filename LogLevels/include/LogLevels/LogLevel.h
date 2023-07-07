#pragma once

/**
*   These are my favorite logging levels:
*      logz
*          Easy, temporary, local debugging. Should not be merged into releases.
*      Info
*          Important milestones that are always good to see, like user clicks, initialization complete, etc. Use sparingly.
*      Error
*          Something went wrong. Having this separate from "Info" is what allows it to have extra flare, like red highlighting and such in some IDEs.
*      Warning
*          Something might be wrong. Having this separate from "Info" is what allows it to have extra flare, like yellow highlighting and such in some IDEs.
*      Debug
*          Allows you to commit useful logs without having to see them unless you want to.
*      Verbose
*          For long, flooding messages.

*   I generally like to keep the log level at ERROR, and then change it to DEBUG or VERBOSE if I realize that I want to see one of those logs, and don't mind filtering and/or scrolling to see.
 */

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
