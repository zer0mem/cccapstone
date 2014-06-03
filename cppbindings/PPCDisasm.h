#pragma once

#include "PPC.hpp"

class CPPCDisasm :
	public CPPCArch
{
public:
	CPPCDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "PPC-64 (PPC syntax, big endian)"
		) : CPPCArch(mode, comment)
	{
	}
};
