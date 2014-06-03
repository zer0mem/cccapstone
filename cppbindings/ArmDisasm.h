#pragma once

#include "Arm64.hpp"
#include "Arm.hpp"

class CArmDisasm64 :
	public CArm64Arch
{
public:
	CArmDisasm64(
		__in unsigned int mode = cs_mode::CS_MODE_THUMB + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in const char* comment = "ARM64 (ARM syntax)"
		) : CArm64Arch(mode, comment)
	{
	}
};

class CArmDisasm86 :
	public CArmArch
{
public:
	CArmDisasm86(
		__in unsigned int mode = cs_mode::CS_MODE_THUMB + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in const char* comment = "ARM32 (ARM syntax)"
		) : CArmArch(mode, comment)
	{
	}
};
