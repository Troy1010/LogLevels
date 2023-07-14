#pragma once
#include "Control.h"

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

std::string ToHexString(UInt32 value);
const bool Contains(std::set<UInt32> cSet, UInt32 vItem);
const bool Contains(std::set<UInt8> cSet, UInt8 vItem);
void SafeConsolePrint(std::string sString);

static ParamInfo kParams_ThreeInts[3] =
{
	{	"int", kParamType_Integer, 0 },
	{	"int", kParamType_Integer, 0 },
	{	"int", kParamType_Integer, 0 },
};

static ParamInfo kParams_RegisterControl[3] =
{
	{	"ref", kParamType_InventoryObject, 0},
	{	"dxScancode", kParamType_Integer, 1 },
	{	"MenuModeType. 0:Game 1:Menu 2:Both", kParamType_Integer, 1 },
};

static ParamInfo kParams_OneRef[1] =
{
	{	"ref", kParamType_InventoryObject, 0},
};

static ParamInfo kParams_Array[1] =
{
	{ "array var", kParamType_Array, 0 },
};
