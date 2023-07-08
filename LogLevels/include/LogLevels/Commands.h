#pragma once

#include "obse/PluginAPI.h"
#include "obse/CommandTable.h"
#if OBLIVION
#include "obse/GameAPI.h"
#else
#include "obse_editor/EditorAPI.h"
#endif
#include "obse/ParamInfos.h"
#include <vector>
#include <set>
#include "Control.h"
#include <string>
#include "TM_CommonCPP/ToLogStr.h"
#include "TM_CommonCPP/StdStringFromFormatString.h"
#include "ToLogStrOverloads.h"
#include "obse/Script.h"
// #include "obse/Hooks_DirectInput8Create.h"
#include <sstream>

#include "Logging.h"
#include "Misc.h"

extern CommandInfo(kCommandInfo_PlaygroundLogLevels);
extern CommandInfo(kCommandInfo_Logz);
extern CommandInfo(kCommandInfo_Logd);
extern CommandInfo(kCommandInfo_Logi);
extern CommandInfo(kCommandInfo_Loge);
extern CommandInfo(kCommandInfo_Logw);
extern CommandInfo(kCommandInfo_Logv);
extern CommandInfo(kCommandInfo_Logf);
extern CommandInfo(kCommandInfo_SetGlobalLogLevel);
extern CommandInfo(kCommandInfo_SetModLogLevel);
extern CommandInfo(kCommandInfo_LogLevelNone);
extern CommandInfo(kCommandInfo_LogLevelTemporary);
extern CommandInfo(kCommandInfo_LogLevelInfo);
extern CommandInfo(kCommandInfo_LogLevelWarning);
extern CommandInfo(kCommandInfo_LogLevelError);
extern CommandInfo(kCommandInfo_LogLevelDebug);
extern CommandInfo(kCommandInfo_LogLevelVerbose);
extern CommandInfo(kCommandInfo_LogLevelFlooding);
extern CommandInfo(kCommandInfo_ShouldLog);
