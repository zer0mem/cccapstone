#pragma once

#include "Sparc.hpp"

class CSparcV9Disasm :
	public CSparcArch
{
public:
	CSparcV9Disasm(
		__in unsigned int mode = cs_mode::CS_MODE_V9 + cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "SparcV9 mode (SPARC syntax, big endian)"
		) : CSparcArch(mode, comment)
	{
	}
};

class CSparcDisasm :
	public CSparcArch
{
public:
	CSparcDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "Sparc mode (SPARC syntax, big endian)"
		) : CSparcArch(mode, comment)
	{
	}
};
