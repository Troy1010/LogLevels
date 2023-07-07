#include "..\include\LogLevels\Commands.h"

#include "Globals.h"


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

// # SetModLogLevel
bool Cmd_SetModLogLevel_Execute(COMMAND_ARGS)
{
    int data;
    if (ExtractArgs(PASS_EXTRACT_ARGS, &data))
    {
        try
        {
            const auto logLevel = static_cast<LogLevel::Enum>(data);
            g_LogLevelModMap[scriptObj->GetModIndex()] = logLevel;
        }
        catch (const std::exception& e)
        {
            InternalLog(std::string(__func__) + "Failure: " + e.what());
        }
    }
    else
    {
        InternalLog(std::string(__func__) + "Could not extract args.");
    }
    return true;
}

DEFINE_COMMAND_PLUGIN(SetModLogLevel, "Sets the log level for this mod", 0, 1, kParams_OneInt)

// # SetGlobalLogLevel
bool Cmd_SetGlobalLogLevel_Execute(COMMAND_ARGS)
{
    int data;
    if (ExtractArgs(PASS_EXTRACT_ARGS, &data))
    {
        try
        {
            g_LogLevel = static_cast<LogLevel::Enum>(data);
        }
        catch (const std::exception& e)
        {
            InternalLog(std::string(__func__) + "Could not cast arg into LogLevel enum." + e.what());
        }
    }
    else
    {
        InternalLog(std::string(__func__) + "Could not extract args.");
    }
    return true;
}

DEFINE_COMMAND_PLUGIN(SetGlobalLogLevel, "Sets the log level", 0, 1, kParams_OneInt)

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
    if (!ShouldLog(scriptObj->GetModIndex(), LogLevel::DEBUGZ))
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
