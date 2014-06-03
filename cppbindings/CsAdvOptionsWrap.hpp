#pragma once

#include "CsCapstoneWrap.h"

class CCsAdvancedOptionsWrapper :
	public CCsHandleHolder
{
public:
	void
	SetSyntax(
		__in cs_opt_value syntax
		)
	{
		cs_option(CsHandle(), cs_opt_type::CS_OPT_SYNTAX, syntax);
	}

	__forceinline
	void
	SetDetail(
		__in cs_opt_value detailedInfo
		)
	{
		cs_option(CsHandle(), cs_opt_type::CS_OPT_DETAIL, detailedInfo);
	}

	__forceinline
	void
	SetMode(
		__in cs_opt_value mode
		)
	{
		cs_option(CsHandle(), cs_opt_type::CS_OPT_MODE, mode);
	}

	__forceinline
	void
	SetMem(
		__in cs_opt_value mem
		)
	{
		cs_option(CsHandle(), cs_opt_type::CS_OPT_MEM, mem);
	}

	__forceinline
	void
	SetSkipData(
		__in cs_opt_value skipData
		)
	{
		cs_option(CsHandle(), cs_opt_type::CS_OPT_SKIPDATA, skipData);
	}

	__forceinline
	void
	SetSkipDataCallback(
		__in cs_opt_skipdata& dataCallbackSetup
		)
	{
		SetSkipData(CS_OPT_ON);
		cs_option(CsHandle(), cs_opt_type::CS_OPT_SKIPDATA_SETUP, reinterpret_cast<size_t>(&dataCallbackSetup));
	}
};
