#pragma once
#include "Misc.h"

extern IDebugLog		gLog; //Log
void FnDebug(std::string sString);
#define DebugCC(iLvl,sTxt) if (LogLevel >= (iLvl)) {FnDebug(sTxt);};
#define logz(sTxt) if (LogLevel >= -1) {FnDebug(sTxt);};
#define Logi(sTxt) if (LogLevel >= 1) {FnDebug(sTxt);};
#define Loge(sTxt) if (LogLevel >= 1) {FnDebug("!ERR!`" + std::string(sTxt));};
#define Logw(sTxt) if (LogLevel >= 1) {FnDebug("!WARN!`" + std::string(sTxt));};
#define Logd(sTxt) if (LogLevel >= 2) {FnDebug(sTxt);};
#define Logv(sTxt) if (LogLevel >= 6) {FnDebug(sTxt);};