#pragma once

#include "CsCapstoneWrap.h"

class CCsAdvancedOptionsWrapper :
	public CCsHandleHolder
{
public:
	/*
		cs_opt_value::CS_OPT_SYNTAX_DEFAULT = 0, // Default asm syntax (CS_OPT_SYNTAX).
		cs_opt_value::CS_OPT_SYNTAX_INTEL, // X86 Intel asm syntax - default on X86 (CS_OPT_SYNTAX).
		cs_opt_value::CS_OPT_SYNTAX_ATT,   // X86 ATT asm syntax (CS_OPT_SYNTAX).
		cs_opt_value::CS_OPT_SYNTAX_NOREGNAME, // Prints register name with only number (CS_OPT_SYNTAX)
		
		http://capstone-engine.org/lang_c.html
	*/
	__forceinline
	__checkReturn
	bool
	SetSyntax(
		__in cs_opt_value syntax
		)
	{
		return !cs_option(CsHandle(), cs_opt_type::CS_OPT_SYNTAX, syntax);
	}

	/*
		How detailed info in included per insn :

		cs_opt_value::CS_OPT_OFF //by default
		cs_opt_value::CS_OPT_ON
	*/
	__forceinline
	__checkReturn
	bool
	SetDetail(
		__in cs_opt_value detailedInfo
		)
	{
		return !cs_option(CsHandle(), cs_opt_type::CS_OPT_DETAIL, detailedInfo);
	}

	/*
		change mode at runtime : 

		cs_mode::CS_MODE_LITTLE_ENDIAN = 0,	// little endian mode (default mode)
		cs_mode::CS_MODE_ARM = 0,	// 32-bit ARM
		cs_mode::CS_MODE_16 = 1 << 1,	// 16-bit mode
		cs_mode::CS_MODE_32 = 1 << 2,	// 32-bit mode
		cs_mode::CS_MODE_64 = 1 << 3,	// 64-bit mode
		cs_mode::CS_MODE_THUMB = 1 << 4,	// ARM's Thumb mode, including Thumb-2
		cs_mode::CS_MODE_MICRO = 1 << 4, // MicroMips mode (MIPS architecture)
		cs_mode::CS_MODE_N64 = 1 << 5, // Nintendo-64 mode (MIPS architecture)
		cs_mode::CS_MODE_V9 = 1 << 4, // SparcV9 mode (Sparc architecture)
		cs_mode::CS_MODE_BIG_ENDIAN = 1 << 31	// big endian mode

		http://capstone-engine.org/lang_c.html
	*/
	__forceinline
	__checkReturn
	bool
	SetMode(
		__in cs_mode mode
		)
	{
		return !cs_option(CsHandle(), cs_opt_type::CS_OPT_MODE, mode);
	}

	/*
		possibility to redefining of mem mgr functions : 

		void *malloc(size_t size);
		void *calloc(size_t nmemb, size_t size);
		void *realloc(void *ptr, size_t size);
		void  free(void *ptr);
		int   vsnprintf(char *str, size_t size, const char *format, va_list ap);

		http://capstone-engine.org/embed.html
	*/
	__forceinline
	__checkReturn
	bool
	SetMemMgrFunc(
		__in cs_opt_mem& memMgrSetup
		)
	{
		return !cs_option(CsHandle(), cs_opt_type::CS_OPT_MEM, reinterpret_cast<size_t>(&memMgrSetup));
	}
	
	/*
		what to do when hitting *broken* instruction

		cs_opt_value::CS_OPT_OFF = stop //by default
		cs_opt_value::CS_OPT_ON = continue (+ write .byte prefix)

		http://capstone-engine.org/skipdata.html
	*/
	__forceinline
	__checkReturn
	bool
	SetSkipData(
		__in cs_opt_value skipData
		)
	{
		return !cs_option(CsHandle(), cs_opt_type::CS_OPT_SKIPDATA, skipData);
	}

	/*
		Define our mneomic alternative to .byte or/and callback at *broken* instructions

		cs_skipdata_cb_t callback :
			return 0 if want to stop disassembling
			return <size> how many bytes to skip (cover by mnemonic)

		-> example : https://github.com/aquynh/capstone/blob/next/tests/test_skipdata.c
		http://capstone-engine.org/skipdata.html
	*/
	__forceinline
	__checkReturn
	bool
	SetSkipDataCallback(
		__in cs_opt_skipdata& dataCallbackSetup
		)
	{
		if (!SetSkipData(CS_OPT_ON))
			return false;
		return !cs_option(CsHandle(), cs_opt_type::CS_OPT_SKIPDATA_SETUP, reinterpret_cast<size_t>(&dataCallbackSetup));
	}
};
