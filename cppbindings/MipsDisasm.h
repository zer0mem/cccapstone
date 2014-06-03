#pragma once

#include "Mips.hpp"

class CMicroMipsCDisasm :
	public CMipsArch
{
public:
	CMicroMipsCDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_MICRO + cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "Micro (MIPS 32b syntax, big endian)"
		) : CMipsArch(mode, comment)
	{
	}
};

class CN64MipsCDisasm :
	public CMipsArch
{
public:
	CN64MipsCDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_N64 + cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "N64 (MIPS 64b syntax, big endian)"
		) : CMipsArch(mode, comment)
	{
	}
};
