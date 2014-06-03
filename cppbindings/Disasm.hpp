#pragma once

#include <capstone.h>
#include <memory>

#include "CsOpcodeInfoWrap.hpp"
#include "InsInfo.hpp"

struct CS_PLATFORM
{
	cs_arch Arch;
	cs_mode Mode;
	const char* Comment;
	cs_opt_type Type;
	cs_opt_value Value;

	cs_opt_type SkipDataType;
	cs_opt_skipdata SkipData;
};

struct CS_INSN_HOLDER
{
	size_t Size;
	const void* Address;

	size_t Count;
	cs_insn* Instructions;

	CS_INSN_HOLDER(
		__in const void* address,
		__in size_t size
		) : Address(address), 
			Size(size)
	{
		Count = 0;
		Instructions = nullptr;
	}

	~CS_INSN_HOLDER()
	{
		cs_free(Instructions, Count);
	}
};

class CDisasmbler :
	public CCsOpcodeInfoWrapper
{
public:
	CDisasmbler(
		__in unsigned int mode,
		__in const char* comment,
		__in cs_arch arch,
		__in cs_opt_type type,
		__in cs_opt_value value,
		__in cs_opt_type skipDataType = static_cast<cs_opt_type>(0),
		__in cs_opt_skipdata skipData = { nullptr, nullptr, nullptr }
		) : m_platform({ arch, static_cast<cs_mode>(mode), nullptr, type, value, skipDataType, skipData })
	{
		m_err = cs_open(m_platform.Arch, m_platform.Mode, &m_csh.Handle);
		if (m_err)
			return;

		if (m_platform.Type)
			cs_option(m_csh.Handle, m_platform.Type, m_platform.Value);

		if (!skipDataType)
			return;

		cs_option(m_csh.Handle, CS_OPT_SKIPDATA, CS_OPT_ON);
		cs_option(m_csh.Handle, m_platform.SkipDataType, reinterpret_cast<size_t>(&m_platform.SkipData));
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
			i_holder->Count = cs_disasm_ex(m_csh.Handle, reinterpret_cast<const unsigned char*>(code), size, baseAddr, 0, &i_holder->Instructions);
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
