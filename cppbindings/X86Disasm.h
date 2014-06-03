#pragma once

#include "X86.hpp"

class CX86Disasm64 :
	public CX86Arch
{
public:
	CX86Disasm64(
		__in unsigned int mode = cs_mode::CS_MODE_64 + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in const char* comment = "X86 64 (Intel syntax)"
		) : CX86Arch(mode, comment)
	{
	}
};

class CX86Disasm86 :
	public CX86Arch
{
public:
	CX86Disasm86(
		__in unsigned int mode = cs_mode::CS_MODE_32 + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in const char* comment = "X86 32 (Intel syntax)"
		) : CX86Arch(mode, comment)
	{
	}
};

class CX86Disasm16 :
	public CX86Arch
{
public:
	CX86Disasm16(
		__in unsigned int mode = cs_mode::CS_MODE_16 + cs_mode::CS_MODE_LITTLE_ENDIAN,
		__in const char* comment = "X86 16 (Intel syntax)"
		) : CX86Arch(mode, comment)
	{
	}
};
