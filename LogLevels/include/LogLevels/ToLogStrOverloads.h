#pragma once

#include "TM_CommonCPP/ToLogStr.h"

namespace TMC
{
	std::string ToLogStr(std::set<UInt8> cSet);
	std::string ToLogStr(UInt8 vUInt8);
	std::string ToLogStr(UInt32 vUInt32);
}