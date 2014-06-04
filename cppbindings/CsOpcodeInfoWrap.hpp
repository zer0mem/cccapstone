#pragma once

#include "CsCapstoneWrap.h"

class CCsOpcodeInfoWrapper
{
protected:
	CS_HANDLE m_csh;

protected:
	__forceinline
	bool 
	IsInInsGroup(
		__in cs_insn& ins,
		__in unsigned int groupId
		)
	{
		return cs_insn_group(m_csh.Handle, &ins, groupId);
	}

	__forceinline
	bool 
	RegRead(
		__in cs_insn& ins,
		__in unsigned int regId
		)
	{
		return cs_reg_read(m_csh.Handle, &ins, regId);
	}

	__forceinline
	bool 
	RegWrite(
		__in cs_insn& ins,
		__in unsigned int regId
		)
	{
		return cs_reg_write(m_csh.Handle, &ins, regId);
	}

	__forceinline
	int
	OpcodeCount(
		__in cs_insn& ins, 
		__in unsigned int opType
		)
	{
		return cs_op_count(m_csh.Handle, &ins, opType);
	}

	__forceinline
	int
	OpcodeIndex(
		__in cs_insn& ins, 
		__in unsigned int opType,
		__in unsigned int opcodePosition = 0
		)
	{
		return cs_op_index(m_csh.Handle, &ins, opType, opcodePosition);
	}

	__forceinline
	const char* 
	RegName(
		__in unsigned int reg
		)
	{
		return cs_reg_name(m_csh.Handle, reg);
	}

	__forceinline
	const char* 
	InsName(
		__in unsigned int ins
		)
	{
		return cs_insn_name(m_csh.Handle, ins);
	}
};
