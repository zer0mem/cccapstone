#pragma once

#include "CsCapstoneWrap.h"
#include "CsOpcodeInfoWrap.hpp"
#include "CsAdvOptionsWrap.hpp"
#include "InsInfo.hpp"

class CDisasmbler :
	protected CCsHandleHolder,
	public CCsOpcodeInfoWrapper,
	public CCsAdvancedOptionsWrapper
{
	struct CS_PLATFORM
	{
		cs_arch Arch;
		cs_mode Mode;
		const char* Comment;
	};
public:
	CDisasmbler(
		__in unsigned int mode,
		__in const char* comment,
		__in cs_arch arch
		) : m_platform({ arch, static_cast<cs_mode>(mode), nullptr })
	{
		m_err = cs_open(m_platform.Arch, m_platform.Mode, &m_csh.Handle);
	}

	csh&
	CsHandle() override
	{
		return m_csh.Handle;
	}

//////////////////////////////////////////////////////////////////////////
// runtime opcode info
//////////////////////////////////////////////////////////////////////////
	__checkReturn
	std::unique_ptr<CS_INSN_HOLDER>
	Disasm(
		__in const void* code,
		__in size_t size,
		__in size_t baseAddr = 0
		)
	{
		std::unique_ptr<CS_INSN_HOLDER> i_holder(new CS_INSN_HOLDER(code, size));
		if (i_holder.get())
			i_holder->Count = cs_disasm_ex(CsHandle(), reinterpret_cast<const unsigned char*>(code), size, baseAddr, 0, &i_holder->Instructions);
		return i_holder;
	}

	__forceinline
	cs_err
	GetError()
	{
		return m_err;
	}

	__forceinline
	unsigned int
	Version(
		__inout int* major = nullptr,
		__inout int* minor = nullptr
		)
	{
		return cs_version(major, minor);
	}

	__forceinline
	static
	const char* 
	ErrToStr(
		__in cs_err err
		)
	{
		return cs_strerror(err);
	}

protected:
	cs_err m_err;
	CS_PLATFORM m_platform;
};
