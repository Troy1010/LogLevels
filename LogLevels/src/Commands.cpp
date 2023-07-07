#include "..\include\LogLevels\Commands.h"

#include "Settings.h"


// # PlaygroundLogLevels
bool Cmd_PlaygroundLogLevels_Execute(COMMAND_ARGS)
{
    logz(std::string(__func__) + "`Open")

    char data[512];
    if (ExtractArgs(PASS_EXTRACT_ARGS, &data))
    {
        logz(std::string("data:") + data)
    }

    logz(std::string(__func__) + "`Close")
    return true;
}

DEFINE_COMMAND_PLUGIN(PlaygroundLogLevels, "Playground command", 0, 1, kParams_OneString)

// # Logz
bool Cmd_Logz_Execute(COMMAND_ARGS)
{
    char data[512];
    if (ExtractArgs(PASS_EXTRACT_ARGS, &data))
    {
        InternalLog(data);
    }
    else
    {
        InternalLog(std::string(__func__) + "Could not extract args.");
    }
    return true;
}

DEFINE_COMMAND_PLUGIN(Logz, "Playground command", 0, 1, kParams_OneString)

// # Logi
// TODO()
// # Loge
// TODO()
// # Logw
// TODO()
// # Logd
bool Cmd_Logd_Execute(COMMAND_ARGS)
{
    if (g_LogLevel < LogLevel::DEBUGZ)
        return true;
    char data[512];
    if (ExtractArgs(PASS_EXTRACT_ARGS, &data))
    {
        InternalLog(data);
    }
    else
    {
        InternalLog(std::string(__func__) + "Could not extract args.");
    }
    return true;
}

DEFINE_COMMAND_PLUGIN(Logd, "Playground command", 0, 1, kParams_OneString)
// # Logv
// TODO()
