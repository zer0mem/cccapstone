#pragma once

#include "Disasm.hpp"
#include "CsIns.hpp"

using CXCoreInsClass = CCsIns<xcore_insn_group, xcore_reg, xcore_op_type, xcore_insn>;

class CXCoreCDisasm :
	public CCsDisasm<CXCoreInsClass>
{
public:
	CXCoreCDisasm(
		__in cs_mode mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "XCore (XCORE syntax, big endian)"
		) : CCsDisasm(mode, comment, cs_arch::CS_ARCH_XCORE)
	{
	}
};
