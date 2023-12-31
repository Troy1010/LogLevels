#pragma region Includes
#include "obse/PluginAPI.h"
#include "obse/CommandTable.h"
#include "obse_common/SafeWrite.cpp"
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
#include "..\include\LogLevels\ToLogStrOverloads.h"
#include "obse/Script.h"
// #include "obse/Hooks_DirectInput8Create.h"
#include <sstream>
#include "..\include\LogLevels\Logging.h"
#include "..\include\LogLevels\Config.h"
#include "Globals.h"
#include "Misc.h"
#include "QuasiTests.h"
#include "..\include\LogLevels\Commands.h"
#include "TM_CommonCPP/String.h"

inline void NewGameOrLoadGame()
{
	bOblivionLoaded = true; //Because there is no OblivionLoaded event, I think this is the closest I can get. (without using mod helper)
	if (shouldTest)
	{
		QuasiTests::runTests();
	}
}

void Handler_NewGame(void * reserved)
{
	bOblivionLoaded = true; // for sanity, to see the following debug message.
	Logd(std::string(__func__) + "`Open")
	NewGameOrLoadGame();
	Logd(std::string(__func__) + "`Close")
}

void Handler_Load(void * reserved)
{
	Logd(std::string(__func__) + "`Open")
	NewGameOrLoadGame();
	Logd(std::string(__func__) + "`Close")
}

#pragma region LoadCCHandler
extern "C" {
bool OBSEPlugin_Query(const OBSEInterface * obse, PluginInfo * info)
{
	Logd(std::string(__func__) + "`Open")
	info->infoVersion = PluginInfo::kInfoVersion;
	info->name = "LogLevels";
	info->version = 1;
	if(!obse->isEditor)
	{
#if OBLIVION
		if (obse->oblivionVersion != OBLIVION_VERSION) { _ERROR("incorrect Oblivion version (got %08X need %08X)", obse->oblivionVersion, OBLIVION_VERSION); return false; }
#endif	
		if (!(g_arrayIntfc = (OBSEArrayVarInterface*)obse->QueryInterface(kInterface_ArrayVar))) { _ERROR("Array interface not found"); return false; }
	}
	if (obse->obseVersion < OBSE_VERSION_INTEGER) { _MESSAGE("OBSE version too old (got %08X expected at least %08X)", obse->obseVersion, OBSE_VERSION_INTEGER); return false; }
	Logd(std::string(__func__) + "`Close")
	return true;
}
bool OBSEPlugin_Load(const OBSEInterface * obse)
{
	Logd(std::string(__func__) + "`Open")
	g_pluginHandle = obse->GetPluginHandle();
	if (!obse->isEditor)
	{
		if (!(g_serialization = (OBSESerializationInterface *)obse->QueryInterface(kInterface_Serialization))) { _ERROR("serialization interface not found"); return false; }
		if (g_serialization->version < OBSESerializationInterface::kVersion) { _ERROR("incorrect serialization version found (got %08X need %08X)", g_serialization->version, OBSESerializationInterface::kVersion); return false; }
		g_serialization->SetLoadCallback(g_pluginHandle, Handler_Load);
		g_serialization->SetNewGameCallback(g_pluginHandle, Handler_NewGame);
	}
	obse->SetOpcodeBase(0x2A00);
	obse->RegisterCommand(&kCommandInfo_PlaygroundLogLevels);
	obse->RegisterCommand(&kCommandInfo_Logz);
	obse->RegisterCommand(&kCommandInfo_Logd);
	obse->RegisterCommand(&kCommandInfo_Logi);
	obse->RegisterCommand(&kCommandInfo_Loge);
	obse->RegisterCommand(&kCommandInfo_Logw);
	obse->RegisterCommand(&kCommandInfo_Logv);
	obse->RegisterCommand(&kCommandInfo_Logf);
	obse->RegisterCommand(&kCommandInfo_SetGlobalLogLevel);
	obse->RegisterCommand(&kCommandInfo_SetModLogLevel);
	obse->RegisterCommand(&kCommandInfo_LogLevelNone);
	obse->RegisterCommand(&kCommandInfo_LogLevelTemporary);
	obse->RegisterCommand(&kCommandInfo_LogLevelInfo);
	obse->RegisterCommand(&kCommandInfo_LogLevelWarning);
	obse->RegisterCommand(&kCommandInfo_LogLevelError);
	obse->RegisterCommand(&kCommandInfo_LogLevelDebug);
	obse->RegisterCommand(&kCommandInfo_LogLevelVerbose);
	obse->RegisterCommand(&kCommandInfo_LogLevelFlooding);
	obse->RegisterCommand(&kCommandInfo_ShouldLog);

	if (!obse->isEditor)
	{
		// Get an OBSEScriptInterface to use for argument extraction
		g_scriptIntfc = (OBSEScriptInterface*)obse->QueryInterface(kInterface_Script);
		g_commandTableIntfc = (OBSECommandTableInterface*)obse->QueryInterface(kInterface_CommandTable);
	}

	Logd(std::string(__func__) + "`Close")
	return true;
}
};
#pragma endregion
