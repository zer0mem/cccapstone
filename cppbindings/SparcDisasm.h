#pragma once

#include "Disasm.hpp"
#include "CsIns.hpp"

using CSparcInsClass = CCsIns<sparc_insn_group, sparc_reg, sparc_op_type, sparc_insn>;

class CSparcV9Disasm :
	public CCsDisasm<CSparcInsClass>
{
public:
	CSparcV9Disasm(
		__in unsigned int mode = cs_mode::CS_MODE_V9 + cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "SparcV9 mode (SPARC syntax, big endian)"
		) : CCsDisasm(mode, comment, cs_arch::CS_ARCH_SPARC)
	{
	}
};

class CSparcDisasm :
	public CCsDisasm<CSparcInsClass>
{
public:
	CSparcDisasm(
		__in unsigned int mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "Sparc mode (SPARC syntax, big endian)"
		) : CCsDisasm(mode, comment, cs_arch::CS_ARCH_SPARC)
	{
	}
};
