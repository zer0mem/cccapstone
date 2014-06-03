#pragma once

#include "PPC.hpp"

class CPPCDisasm :
	public CPPCArch
{
public:
	CPPCDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in cs_opt_type optType = cs_opt_type::CS_OPT_DETAIL,
		__in cs_opt_value optValue = cs_opt_value::CS_OPT_ON,
		__in const char* comment = "PPC-64 (PPC syntax, big endian)",
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : CPPCArch(mode, optType, optValue, comment, skipDataType, skipData)
	{
	}
};
