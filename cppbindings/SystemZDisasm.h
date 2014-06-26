#pragma once

#include "Disasm.hpp"
#include "CsIns.hpp"

using CSysZInsClass = CCsIns<sysz_insn_group, sysz_reg, sysz_op_type, sysz_insn>;

class CSystemZCDisasm :
	public CCsDisasm<CSysZInsClass>
{
public:
	CSystemZCDisasm(
		__in cs_mode mode = cs_mode::CS_MODE_BIG_ENDIAN,
		__in const char* comment = "SystemZ (SYSZ syntax, big endian)"
		) : CCsDisasm(mode, comment, cs_arch::CS_ARCH_SYSZ)
	{
	}
};
