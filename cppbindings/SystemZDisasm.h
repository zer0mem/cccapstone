#pragma once

#include "SystemZ.hpp"

class CSystemZCDisasm :
	public CSysZArch
{
public:
	CSystemZCDisasm(
		__in cs_mode mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "SystemZ (SYSZ syntax, big endian)"
		) : CSysZArch(mode, comment)
	{
	}
};
