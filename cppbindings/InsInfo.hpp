#pragma once 

#include <capstone.h>
#include <inttypes.h>
                                
/* Second-Best Disassembler Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013> */

namespace instructioninfox86
{
	static void print_string_hex(char *comment, unsigned char *str, int len)
	{
		unsigned char *c;

		printf("%s", comment);
		for (c = str; c < str + len; c++) {
			printf("0x%02x ", *c & 0xff);
		}

		printf("\n");
	}

	static void print_insn_detail(csh handle, cs_mode mode, cs_insn *ins)
	{
		int count, i;
		cs_x86 *x86;

		// detail can be NULL on "data" instruction if SKIPDATA option is turned ON
		if (ins->detail == NULL)
			return;

		x86 = &(ins->detail->x86);

		print_string_hex("\tPrefix:", x86->prefix, 5);

		if (x86->segment != X86_REG_INVALID)
			printf("\tSegment override: %s\n", cs_reg_name(handle, x86->segment));

		print_string_hex("\tOpcode:", x86->opcode, 3);
		printf("\top_size: %u, addr_size: %u, disp_size: %u, imm_size: %u\n", x86->op_size, x86->addr_size, x86->disp_size, x86->imm_size);
		printf("\tmodrm: 0x%x\n", x86->modrm);
		printf("\tdisp: 0x%x\n", x86->disp);

		// SIB is not available in 16-bit mode
		if ((mode & CS_MODE_16) == 0) {
			printf("\tsib: 0x%x\n", x86->sib);
			if (x86->sib_base != X86_REG_INVALID)
				printf("\t\tsib_base: %s\n", cs_reg_name(handle, x86->sib_base));
			if (x86->sib_index != X86_REG_INVALID)
				printf("\t\tsib_index: %s\n", cs_reg_name(handle, x86->sib_index));
			if (x86->sib_scale != 0)
				printf("\t\tsib_scale: %d\n", x86->sib_scale);
		}

		count = cs_op_count(handle, ins, X86_OP_IMM);
		if (count) {
			printf("\timm_count: %u\n", count);
			for (i = 1; i < count + 1; i++) {
				int index = cs_op_index(handle, ins, X86_OP_IMM, i);
				printf("\t\timms[%u]: 0x%"PRIx64 "\n", i, x86->operands[index].imm);
			}
		}

		if (x86->op_count)
			printf("\top_count: %u\n", x86->op_count);
		for (i = 0; i < x86->op_count; i++) {
			cs_x86_op *op = &(x86->operands[i]);
			
			switch((int)op->type) {
				case X86_OP_REG:
					printf("\t\toperands[%u].type: REG = %s\n", i, cs_reg_name(handle, op->reg));
					break;
				case X86_OP_IMM:
					printf("\t\toperands[%u].type: IMM = 0x%"PRIx64 "\n", i, op->imm);
					break;
				case X86_OP_FP:
					printf("\t\toperands[%u].type: FP = %f\n", i, op->fp);
					break;
				case X86_OP_MEM:
					printf("\t\toperands[%u].type: MEM\n", i);
					if (op->mem.base != 0)
						printf("\t\t\toperands[%u].mem.base: REG = %s\n", i, cs_reg_name(handle, op->mem.base));
					if (op->mem.index != 0)
						printf("\t\t\toperands[%u].mem.index: REG = %s\n", i, cs_reg_name(handle, op->mem.index));
					if (op->mem.scale != 1)
						printf("\t\t\toperands[%u].mem.scale: %u\n", i, op->mem.scale);
					if (op->mem.disp != 0)
						printf("\t\t\toperands[%u].mem.disp: 0x%" PRIx64 "\n", i, op->mem.disp);
					break;
				default:
					break;
			}
		}

		printf("\n");
	}
};
