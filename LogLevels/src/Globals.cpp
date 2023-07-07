#include "Globals.h"
#include "Misc.h"

#if OBLIVION
OBSECommandTableInterface * g_commandTableIntfc = nullptr; // assigned in OBSEPlugin_Load
OBSEScriptInterface * g_scriptIntfc = nullptr; //For command argument extraction
#define ExtractArgsEx(...) g_scriptIntfc->ExtractArgsEx(__VA_ARGS__)
#define ExtractFormatStringArgs(...) g_scriptIntfc->ExtractFormatStringArgs(__VA_ARGS__)
#endif

Script* pBlankScript = nullptr;
ScriptEventList * pBlankScriptEventList = nullptr;
OBSESerializationInterface	* g_serialization = nullptr;
PluginHandle				g_pluginHandle = kPluginHandle_Invalid;

const CommandInfo* GetControl_CmdInfo = nullptr;
const CommandInfo* GetAltControl2_CmdInfo = nullptr;
const CommandInfo* ResolveModIndex_CmdInfo = nullptr;
const CommandInfo* IsKeyPressed3_CmdInfo = nullptr;

bool bOblivionLoaded = false; //Because there is no OblivionLoaded event, this variable is set true later than it should be. (without a helper mod)

extern OBSEArrayVarInterface* g_arrayIntfc = nullptr;
