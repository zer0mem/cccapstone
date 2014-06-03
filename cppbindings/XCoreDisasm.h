#pragma once

#include "XCore.hpp"

class CXCoreCDisasm :
	public CXCoreArch
{
public:
	CXCoreCDisasm(
		__in cs_mode mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "XCore (XCORE syntax, big endian)"
		) : CXCoreArch(mode, comment)
	{
	}
};
