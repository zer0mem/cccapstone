#pragma once

#include "Disasm.hpp"
#include "CsIns.hpp"

using CArm64InsClass = CCsIns<arm64_insn_group, arm64_reg, arm64_op_type, arm64_insn>;
using CArmInsClass = CCsIns<arm_insn_group, arm_reg, arm_op_type, arm_insn>;

class CArmDisasm64 :
	public CCsDisasm<CArm64InsClass>
{
public:
	CArmDisasm64(
		__in unsigned int mode = cs_mode::CS_MODE_THUMB + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in const char* comment = "ARM64 (ARM syntax)"
		) : CCsDisasm(mode, comment, cs_arch::CS_ARCH_ARM64)
	{
	}
};

class CArmDisasm86 :
	public CCsDisasm<CArmInsClass>
{
public:
	CArmDisasm86(
		__in unsigned int mode = cs_mode::CS_MODE_THUMB + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in const char* comment = "ARM32 (ARM syntax)"
		) : CCsDisasm(mode, comment, cs_arch::CS_ARCH_ARM)
	{
	}
};
