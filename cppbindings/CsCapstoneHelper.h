#pragma once

#include <capstone.h>
#include <memory>

struct CS_HANDLE :
	public std::shared_ptr<csh>
{
	CS_HANDLE() :
		std::shared_ptr<csh>(&m_handle, cs_close)
	{
	}

private:
	csh m_handle;
};

template<typename CsInsClass_t>
struct CS_INSN_HOLDER
{
	size_t Size;
	const void* Address;
	size_t Count;

	CsInsClass_t
	Instructions(
		__in size_t i
		)
	{
		return CsInsClass_t(m_csh, CsInstructions[i]);
	}

	CS_INSN_HOLDER(
		__in CS_HANDLE& csh,
		__in const void* address,
		__in size_t size
		) : m_csh(csh),
			Address(address),
			Size(size)
	{
		Count = 0;
		CsInstructions = nullptr;
	}

	~CS_INSN_HOLDER()
	{
		cs_free(CsInstructions, Count);
	}

protected:
	template<typename CsInsClass_t>
	friend class CCsDisasm;

	cs_insn* CsInstructions;
	CS_HANDLE m_csh;
};
