#pragma once
#include "LogLevel.h"
#include "Misc.h"

extern IDebugLog gLog; //Log
void InternalLog(std::string sString);
bool InternalShouldLog(int modIndex, LogLevel::Enum logLevel);
#define DebugCC(iLvl,sTxt) if (g_LogLevel >= (iLvl)) {InternalLog(sTxt);};
#define logz(sTxt) if (g_LogLevel >= -1) {InternalLog(sTxt);};
#define Logi(sTxt) if (g_LogLevel >= 1) {InternalLog(sTxt);};
#define Loge(sTxt) if (g_LogLevel >= 1) {InternalLog("!ERR!`" + std::string(sTxt));}; // Normally, the IDE will highlight errors and warnings.. but I have no such mechanism atm, so I've added this prefix instead.
#define Logw(sTxt) if (g_LogLevel >= 1) {InternalLog("!WARN!`" + std::string(sTxt));}; // Normally, the IDE will highlight errors and warnings.. but I have no such mechanism atm, so I've added this prefix instead.
#define Logd(sTxt) if (g_LogLevel >= 2) {InternalLog(sTxt);};
#define Logv(sTxt) if (g_LogLevel >= 6) {InternalLog(sTxt);};
