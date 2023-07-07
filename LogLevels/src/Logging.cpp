#include "..\include\LogLevels\Logging.h"

#include "Settings.h"
#include "TM_CommonCPP/String.h"

IDebugLog		gLog(DebugLogName); //Log

void FnDebug(std::string sString)
{
	SafeConsolePrint(sString);
	_MESSAGE(TMC::Str::Replace(sString,"%","").c_str());
}
