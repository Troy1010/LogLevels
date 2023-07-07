#include "..\include\LogLevels\Logging.h"

#include "Globals.h"
#include "Settings.h"
#include "TM_CommonCPP/String.h"

IDebugLog gLog(DebugLogName); //Log

void InternalLog(std::string sString)
{
    SafeConsolePrint(sString);
    // I can see there are already some log mechanisms like _DMESSAGE, _VMESSAGE.. perhaps I might want to build off of those instead, at some point.
    _MESSAGE(TMC::Str::Replace(sString, "%", "").c_str());
}

bool ShouldLog(int modIndex, LogLevel::Enum logLevel)
{
    return g_LogLevelModMap.contains(modIndex) && g_LogLevelModMap[modIndex] >= logLevel
        && g_LogLevel >= logLevel;
}
