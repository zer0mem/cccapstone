#pragma once

#include "Disasm.hpp"

class CArm64Arch :
	public CDisasmbler
{
protected:
	CArm64Arch(
		__in unsigned int mode,
		__in const char* comment
		) : CDisasmbler(mode, comment, cs_arch::CS_ARCH_ARM64)
	{
	}

public:
	__forceinline
	bool 
	IsInInsGroup(
		__in cs_insn& ins,
		__in arm64_insn_group groupId
		)
	{
		return CDisasmbler::IsInInsGroup(ins, groupId);
	}
	
	__forceinline
	bool 
	RegRead(
		__in cs_insn& ins,
		__in arm64_reg regId
		)
	{
		return CDisasmbler::RegRead(ins, regId);
	}

	__forceinline
	bool 
	RegWrite(
		__in cs_insn& ins,
		__in arm64_reg regId
		)
	{
		return CDisasmbler::RegWrite(ins, regId);
	}

	__forceinline
	int
	OpcodeCount(
		__in cs_insn& ins, 
		__in arm64_op_type opType
		)
	{
		return CDisasmbler::OpcodeCount(ins, opType);
	}

	__forceinline
	int
	OpcodeIndex(
		__in cs_insn& ins, 
		__in arm64_op_type opType,
		__in unsigned int opPosition = 0
		)
	{
		return CDisasmbler::OpcodeIndex(ins, opType, opPosition);
	}

	__forceinline
	const char* 
	RegName(
		__in arm64_reg reg
		)
	{
		return CDisasmbler::RegName(reg);
	}

	__forceinline
	const char* 
	InsName(
		__in arm64_insn ins
		)
	{
		return CDisasmbler::InsName(ins);
	}
};
