#include "Misc.h"
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
#include "..\include\LogLevels\ToLogStrOverloads.h"
#include "obse/Script.h"
// #include "obse/Hooks_DirectInput8Create.h"
#include <sstream>

#include "Globals.h"
#include "..\include\LogLevels\Config.h"
#include "..\include\LogLevels\Logging.h"

std::string ToHexString(UInt32 value)
{
	std::stringstream ss;
	ss << std::hex << value;  // Convert to hexadecimal

	std::string hexString = ss.str();

	// If the value is less than 0x10000000, prepend zeros to the string
	while (hexString.length() < 8)
		hexString = "0" + hexString;

	return hexString;
}

const bool Contains(std::set<UInt32> cSet, UInt32 vItem)
{
	return cSet.find(vItem) != cSet.end();
}
const bool Contains(std::set<UInt8> cSet, UInt8 vItem)
{
	return cSet.find(vItem) != cSet.end();
}

void SafeConsolePrint(std::string sString)
{
	if (!bOblivionLoaded) // Trying to print to console without Oblivion loaded causes CTD.
	{
		//do nothing
	}
	else if (sString.length() < 1000) //1000 might not be the exact limit. Exceeding limit causes CTD.
	{
		Console_Print(sString.c_str());
	}
	else
	{
		Console_Print(sString.substr(0, 1000).c_str());
		Console_Print("<MessageTooLarge>");
	}
}

