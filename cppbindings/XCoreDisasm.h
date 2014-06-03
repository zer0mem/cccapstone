#pragma once

#include "XCore.hpp"

class CXCoreCDisasm :
	public CXCoreArch
{
public:
	CXCoreCDisasm(
		__in cs_mode mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in cs_opt_type optType = cs_opt_type::CS_OPT_DETAIL,
		__in cs_opt_value optValue = cs_opt_value::CS_OPT_ON,
		__in const char* comment = "XCore (XCORE syntax, big endian)",
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : CXCoreArch(mode, optType, optValue, comment, skipDataType, skipData)
	{
	}
};
