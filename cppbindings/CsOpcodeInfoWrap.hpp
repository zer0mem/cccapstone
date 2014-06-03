#pragma once

#include "CsCapstoneWrap.h"

class CCsOpcodeInfoWrapper :
	protected CCsHandleHolder
{	
protected:
	__forceinline
	bool 
	IsInInsGroup(
		__in cs_insn& ins,
		__in unsigned int groupId
		)
	{
		return cs_insn_group(CsHandle(), &ins, groupId);
	}

	__forceinline
	bool 
	RegRead(
		__in cs_insn& ins,
		__in unsigned int regId
		)
	{
		return cs_reg_read(CsHandle(), &ins, regId);
	}

	__forceinline
	bool 
	RegWrite(
		__in cs_insn& ins,
		__in unsigned int regId
		)
	{
		return cs_reg_write(CsHandle(), &ins, regId);
	}

	__forceinline
	int
	OpcodeCount(
		__in cs_insn& ins, 
		__in unsigned int opType
		)
	{
		return cs_op_count(CsHandle(), &ins, opType);
	}

	__forceinline
	int
	OpcodeIndex(
		__in cs_insn& ins, 
		__in unsigned int opType,
		__in unsigned int opcodePosition = 0
		)
	{
		return cs_op_index(CsHandle(), &ins, opType, opcodePosition);
	}

	__forceinline
	const char* 
	RegName(
		__in unsigned int reg
		)
	{
		return cs_reg_name(CsHandle(), reg);
	}

	__forceinline
	const char* 
	InsName(
		__in unsigned int ins
		)
	{
		return cs_insn_name(CsHandle(), ins);
	}
};
