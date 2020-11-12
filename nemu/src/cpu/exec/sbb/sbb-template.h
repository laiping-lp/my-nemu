#include "cpu/exec/template-start.h"

#define instr sbb

static void do_execute () {
	DATA_TYPE src = op_src -> val;
    //converse
    if(op_src->size == 1 && op_dest->size != 1){
        op_src->val = (int8_t)op_src->val;
    }
    src += cpu.CF;
    DATA_TYPE temp = op_dest -> val - src;

	int len = (DATA_BYTE << 3) - 1; //DATA_BYTE * 8 -1
    cpu.CF = op_dest -> val < src; 
    //sign flag:set equal to high-order bit of result(0 is positive)
    cpu.SF = temp >> len;
    //zero flag:set if result is zero,clear otherwise 
    cpu.ZF = !temp;
    
    int t1,t2;
    t1 = op_dest -> val >> len;
    t2 = src >> len;
    cpu.OF = (t1 != t2 && t2 == cpu.SF);
    //parity flag:set on low-order eight bits of result contain an even number of 1 bits;cleared otherwise
    OPERAND_W(op_dest, temp);//write in the res
    temp ^= temp >> 4;
    temp ^= temp >> 2;
    temp ^= temp >> 1;
    cpu.PF = !(temp & 1);
	print_asm_template2();
}

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif

make_instr_helper(i2a)
make_instr_helper(i2rm)
make_instr_helper(r2rm)
make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"