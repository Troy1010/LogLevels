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
            auto modIndex = scriptObj->GetModIndex();
            auto logLevel = static_cast<LogLevel::Enum>(data);
            InternalSetLogLevel(modIndex, logLevel);
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

DEFINE_COMMAND_PLUGIN(SetGlobalLogLevel, "Sets a log level cap for all mods", 0, 1, kParams_OneInt)

// # Logz
bool Cmd_Logz_Execute(COMMAND_ARGS)
{
    if (!InternalShouldLog(scriptObj->GetModIndex(), LogLevel::TEMPORARY))
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

DEFINE_COMMAND_PLUGIN(Logz, "Log if log level is <= LogLevel::TEMPORARY", 0, 1, kParams_OneString)

// # Logi
bool Cmd_Logi_Execute(COMMAND_ARGS)
{
    if (!InternalShouldLog(scriptObj->GetModIndex(), LogLevel::INFO))
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

DEFINE_COMMAND_PLUGIN(Logi, "Log if log level is <= LogLevel::INFO", 0, 1, kParams_OneString)
// # Loge
bool Cmd_Loge_Execute(COMMAND_ARGS)
{
    if (!InternalShouldLog(scriptObj->GetModIndex(), LogLevel::ERRORZ))
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

DEFINE_COMMAND_PLUGIN(Loge, "Log if log level is <= LogLevel::ERRORZ", 0, 1, kParams_OneString)
// # Logw
bool Cmd_Logw_Execute(COMMAND_ARGS)
{
    if (!InternalShouldLog(scriptObj->GetModIndex(), LogLevel::WARNING))
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

DEFINE_COMMAND_PLUGIN(Logw, "Log if log level is <= LogLevel::WARNING", 0, 1, kParams_OneString)
// # Logd
bool Cmd_Logd_Execute(COMMAND_ARGS)
{
    if (!InternalShouldLog(scriptObj->GetModIndex(), LogLevel::DEBUGZ))
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

DEFINE_COMMAND_PLUGIN(Logd, "Log if log level is <= LogLevel::DEBUGZ", 0, 1, kParams_OneString)
// # Logv
bool Cmd_Logv_Execute(COMMAND_ARGS)
{
    if (!InternalShouldLog(scriptObj->GetModIndex(), LogLevel::VERBOSE))
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

DEFINE_COMMAND_PLUGIN(Logv, "Log if log level is <= LogLevel::VERBOSE", 0, 1, kParams_OneString)
// # Logf
bool Cmd_Logf_Execute(COMMAND_ARGS)
{
    if (!InternalShouldLog(scriptObj->GetModIndex(), LogLevel::FLOODING))
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

DEFINE_COMMAND_PLUGIN(Logf, "Log if log level is <= LogLevel::FLOODING", 0, 1, kParams_OneString)
// # LogLevelNone
bool Cmd_LogLevelNone_Execute(COMMAND_ARGS)
{
    *result = static_cast<int>(LogLevel::NONE);
    return true;
}

DEFINE_COMMAND_PLUGIN(LogLevelNone, "Returns int value for LogLevel", 0, 0, nullptr)
// # LogLevelTemporary
bool Cmd_LogLevelTemporary_Execute(COMMAND_ARGS)
{
    *result = static_cast<int>(LogLevel::TEMPORARY);
    return true;
}

DEFINE_COMMAND_PLUGIN(LogLevelTemporary, "Returns int value for LogLevel", 0, 0, nullptr)
// # LogLevelInfo
bool Cmd_LogLevelInfo_Execute(COMMAND_ARGS)
{
    *result = static_cast<int>(LogLevel::INFO);
    return true;
}

DEFINE_COMMAND_PLUGIN(LogLevelInfo, "Returns int value for LogLevel", 0, 0, nullptr)
// # LogLevelError
bool Cmd_LogLevelError_Execute(COMMAND_ARGS)
{
    *result = static_cast<int>(LogLevel::ERRORZ);
    return true;
}

DEFINE_COMMAND_PLUGIN(LogLevelError, "Returns int value for LogLevel", 0, 0, nullptr)
// # LogLevelError
bool Cmd_LogLevelWarning_Execute(COMMAND_ARGS)
{
    *result = static_cast<int>(LogLevel::WARNING);
    return true;
}

DEFINE_COMMAND_PLUGIN(LogLevelWarning, "Returns int value for LogLevel", 0, 0, nullptr)
// # LogLevelDebug
bool Cmd_LogLevelDebug_Execute(COMMAND_ARGS)
{
    *result = static_cast<int>(LogLevel::DEBUGZ);
    return true;
}

DEFINE_COMMAND_PLUGIN(LogLevelDebug, "Returns int value for LogLevel", 0, 0, nullptr)
// # LogLevelVerbose
bool Cmd_LogLevelVerbose_Execute(COMMAND_ARGS)
{
    *result = static_cast<int>(LogLevel::VERBOSE);
    return true;
}

DEFINE_COMMAND_PLUGIN(LogLevelVerbose, "Returns int value for LogLevel", 0, 0, nullptr)
// # LogLevelFlooding
bool Cmd_LogLevelFlooding_Execute(COMMAND_ARGS)
{
    *result = static_cast<int>(LogLevel::FLOODING);
    return true;
}

DEFINE_COMMAND_PLUGIN(LogLevelFlooding, "Returns int value for LogLevel", 0, 0, nullptr)
// # ShouldLog
bool Cmd_ShouldLog_Execute(COMMAND_ARGS)
{
    int data;
    if (ExtractArgs(PASS_EXTRACT_ARGS, &data))
    {
        try
        {
            const auto logLevel = static_cast<LogLevel::Enum>(data);
            *result = InternalShouldLog(scriptObj->GetModIndex(), logLevel);
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

DEFINE_COMMAND_PLUGIN(ShouldLog, "True if should log, false otherwise", 0, 1, kParams_OneInt)
