#include "cpu/exec/template-start.h"

#define instr test

static void do_execute () {
	DATA_TYPE temp = op_dest->val & op_src->val;
    cpu.CF = 0; //carry flag
    cpu.OF = 0; //overflow flag

    int len = (DATA_BYTE << 3) - 1; //DATA_BYTE * 8 -1

    //sign flag:set equal to high-order bit of result(0 is positive)
    cpu.SF = temp >> len;
    //zero flag:set if result is zero,clear otherwise 
    cpu.ZF = !temp;
    //parity flag:set on low-order eight bits of result contain an even number of 1 bits;cleared otherwise
    temp ^= temp >> 4;
    temp ^= temp >> 2;
    temp ^= temp >> 1;
    cpu.PF = !(temp & 1);
	print_asm_template2();
}

make_instr_helper(i2a)
make_instr_helper(i2rm)
make_instr_helper(r2rm)


#include "cpu/exec/template-end.h"