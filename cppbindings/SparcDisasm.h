#pragma once

#include "Sparc.hpp"

class CSparcV9Disasm :
	public CSparcArch
{
public:
	CSparcV9Disasm(
		__in unsigned int mode = cs_mode::CS_MODE_V9 + cs_mode::CS_MODE_BIG_ENDIAN,
		__in cs_opt_type optType = cs_opt_type::CS_OPT_DETAIL,
		__in cs_opt_value optValue = cs_opt_value::CS_OPT_ON,
		__in const char* comment = "SparcV9 mode (SPARC syntax, big endian)",
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : CSparcArch(mode, optType, optValue, comment, skipDataType, skipData)
	{
	}
};

class CSparcDisasm :
	public CSparcArch
{
public:
	CSparcDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in cs_opt_type optType = cs_opt_type::CS_OPT_DETAIL,
		__in cs_opt_value optValue = cs_opt_value::CS_OPT_ON,
		__in const char* comment = "Sparc mode (SPARC syntax, big endian)",
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : CSparcArch(mode, optType, optValue, comment, skipDataType, skipData)
	{
	}
};
