#pragma once

#include <capstone.h>
#include <memory>

struct CS_HANDLE :
	protected std::unique_ptr<csh, decltype(&cs_close)>
{
	csh Handle;
	CS_HANDLE() :
		std::unique_ptr<csh, decltype(&cs_close)>(&Handle, cs_close)
	{
	}
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

class CCsHandleHolder
{
protected:
	virtual
	csh&
	CsHandle() = 0;
};
