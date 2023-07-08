#pragma once
#include "LogLevel.h"
#include "Misc.h"
#include "Globals.h"

extern IDebugLog gLog; //Log
void InternalLog(std::string sString);
bool InternalShouldLog(int modIndex, LogLevel::Enum logLevel);
void InternalSetLogLevel(int modIndex, LogLevel::Enum logLevel);
#define logz(sTxt) InternalLog(sTxt);
#define Logi(sTxt) if (g_LogLevelPluginLogLevel >= LogLevel::INFO) {InternalLog(sTxt);};
#define Loge(sTxt) if (g_LogLevelPluginLogLevel >= LogLevel::ERRORZ) {InternalLog(sTxt);};
#define Logw(sTxt) if (g_LogLevelPluginLogLevel >= LogLevel::WARNING) {InternalLog(sTxt);};
#define Logd(sTxt) if (g_LogLevelPluginLogLevel >= LogLevel::DEBUGZ) {InternalLog(sTxt);};
#define Logv(sTxt) if (g_LogLevelPluginLogLevel >= LogLevel::VERBOSE) {InternalLog(sTxt);};
#define Logf(sTxt) if (g_LogLevelPluginLogLevel >= LogLevel::FLOODING) {InternalLog(sTxt);};
