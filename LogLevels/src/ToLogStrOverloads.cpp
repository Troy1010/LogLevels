#include "..\include\LogLevels\ToLogStrOverloads.h"
#include <sstream>

#include "TM_CommonCPP/ToLogStr.h"

namespace TMC
{
	std::string ToLogStr(std::set<UInt8> cSet)
	{
		return LogStrFactory::ToLogStr_Collection(cSet);
	}
	std::string ToLogStr(UInt8 vUInt8)
	{
		return std::to_string(vUInt8);
	}
	std::string ToLogStr(UInt32 vUInt32)
	{
		return std::to_string(vUInt32);
	}
}
