#include "cpu/exec/template-start.h"

#define instr jae

static void do_execute () {
	DATA_TYPE_S temp = op_src -> val;
    print_asm("jae %x", cpu.eip + 1 + DATA_BYTE + temp);
    if(cpu.CF == 0) 
        cpu.eip += temp;
}

make_instr_helper(i)

#include "cpu/exec/template-end.h"