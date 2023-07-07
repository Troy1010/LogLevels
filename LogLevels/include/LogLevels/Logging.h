#pragma once
#include "Misc.h"

extern IDebugLog		gLog; //Log
void FnDebug(std::string sString);
#define DebugCC(iLvl,sTxt) if (logLevel >= (iLvl)) {FnDebug(sTxt);};
#define logz(sTxt) if (logLevel >= -1) {FnDebug(sTxt);};
#define Logi(sTxt) if (logLevel >= 1) {FnDebug(sTxt);};
#define Loge(sTxt) if (logLevel >= 1) {FnDebug("!ERR!`" + std::string(sTxt));};
#define Logw(sTxt) if (logLevel >= 1) {FnDebug("!WARN!`" + std::string(sTxt));};
#define Logd(sTxt) if (logLevel >= 2) {FnDebug(sTxt);};
#define Logv(sTxt) if (logLevel >= 6) {FnDebug(sTxt);};