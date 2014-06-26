#pragma once

#include "Disasm.hpp"
#include "CsIns.hpp"

using CMipsInsClass = CCsIns<mips_insn_group, mips_reg, mips_op_type, mips_insn>;

class CMicroMipsCDisasm :
	public CCsDisasm<CMipsInsClass>
{
public:
	CMicroMipsCDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_MICRO + cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "Micro (MIPS 32b syntax, big endian)"
		) : CCsDisasm(mode, comment, cs_arch::CS_ARCH_MIPS)
	{
	}
};

class CN64MipsCDisasm :
	public CCsDisasm<CMipsInsClass>
{
public:
	CN64MipsCDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_N64 + cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "N64 (MIPS 64b syntax, big endian)"
		) : CCsDisasm(mode, comment, cs_arch::CS_ARCH_MIPS)
	{
	}
};
