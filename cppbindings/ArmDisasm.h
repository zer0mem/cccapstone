#pragma once

#include "Arm64.hpp"
#include "Arm.hpp"

class CArmDisasm64 :
	public CArm64Arch
{
public:
	CArmDisasm64(
		__in unsigned int mode = cs_mode::CS_MODE_THUMB + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in cs_opt_type optType = cs_opt_type::CS_OPT_DETAIL,
		__in cs_opt_value optValue = cs_opt_value::CS_OPT_ON,
		__in const char* comment = "ARM64 (ARM syntax)",
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : CArm64Arch(mode, optType, optValue, comment, skipDataType, skipData)
	{
	}
};

class CArmDisasm86 :
	public CArmArch
{
public:
	CArmDisasm86(
		__in unsigned int mode = cs_mode::CS_MODE_THUMB + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in cs_opt_type optType = cs_opt_type::CS_OPT_DETAIL,
		__in cs_opt_value optValue = cs_opt_value::CS_OPT_ON,
		__in const char* comment = "ARM32 (ARM syntax)",
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : CArmArch(mode, optType, optValue, comment, skipDataType, skipData)
	{
	}
};
