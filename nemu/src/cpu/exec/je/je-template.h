#include "cpu/exec/template-start.h"

#define instr je

static void do_execute () {
	DATA_TYPE_S temp = op_src -> val;
	print_asm("je %x", cpu.eip + 1 + DATA_BYTE + temp);
    if(cpu.ZF == 1)
        cpu.eip += temp;
}

make_instr_helper(i)


#include "cpu/exec/template-end.h"
