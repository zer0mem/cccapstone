#pragma once

#include "Disasm.hpp"

class CX86Arch :
	public CDisasmbler
{
protected:
	CX86Arch(
		__in unsigned int mode,
		__in const char* comment
		) : CDisasmbler(mode, comment, cs_arch::CS_ARCH_X86)
	{
	}

public:
	__forceinline
	bool 
	IsInInsGroup(
		__in cs_insn& ins,
		__in x86_insn_group groupId
		)
	{
		return CDisasmbler::IsInInsGroup(ins, groupId);
	}
	
	__forceinline
	bool 
	RegRead(
		__in cs_insn& ins,
		__in x86_reg regId
		)
	{
		return CDisasmbler::RegRead(ins, regId);
	}

	__forceinline
	bool 
	RegWrite(
		__in cs_insn& ins,
		__in x86_reg regId
		)
	{
		return CDisasmbler::RegWrite(ins, regId);
	}

	__forceinline
	int
	OpcodeCount(
		__in cs_insn& ins, 
		__in x86_op_type opType
		)
	{
		return CDisasmbler::OpcodeCount(ins, opType);
	}

	__forceinline
	int
	OpcodeIndex(
		__in cs_insn& ins, 
		__in x86_op_type opType,
		__in unsigned int opPosition = 0
		)
	{
		return CDisasmbler::OpcodeIndex(ins, opType, opPosition);
	}

	__forceinline
	const char* 
	RegName(
		__in x86_reg reg
		)
	{
		return CDisasmbler::RegName(reg);
	}

	__forceinline
	const char* 
	InsName(
		__in x86_insn ins
		)
	{
		return CDisasmbler::InsName(ins);
	}

//////////////////////////////////////////////////////////////////////////
// debug
//////////////////////////////////////////////////////////////////////////
	void 
	PrintInstDetail(
		__in cs_insn& inst
		)
	{
		instructioninfox86::print_insn_detail(CsHandle(), m_platform.Mode, &inst);
	}
};
