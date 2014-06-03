#pragma once

#include "Mips.hpp"

class CMicroMipsCDisasm :
	public CMipsArch
{
public:
	CMicroMipsCDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_MICRO + cs_mode::CS_MODE_BIG_ENDIAN,
		__in cs_opt_type optType = cs_opt_type::CS_OPT_DETAIL,
		__in cs_opt_value optValue = cs_opt_value::CS_OPT_ON,
		__in const char* comment = "Micro (MIPS 32b syntax, big endian)",
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : CMipsArch(mode, optType, optValue, comment, skipDataType, skipData)
	{
	}
};

class CN64MipsCDisasm :
	public CMipsArch
{
public:
	CN64MipsCDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_N64 + cs_mode::CS_MODE_BIG_ENDIAN,
		__in cs_opt_type optType = cs_opt_type::CS_OPT_DETAIL,
		__in cs_opt_value optValue = cs_opt_value::CS_OPT_ON,
		__in const char* comment = "N64 (MIPS 64b syntax, big endian)",
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : CMipsArch(mode, optType, optValue, comment, skipDataType, skipData)
	{
	}
};
