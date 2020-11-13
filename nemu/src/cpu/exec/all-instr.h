#include "prefix/prefix.h"

#include "data-mov/mov.h"
#include "data-mov/xchg.h"
#include "data-mov/movext.h"
#include "data-mov/cltd.h"
#include "data-mov/leave.h"

#include "arith/dec.h"
#include "arith/inc.h"
#include "arith/neg.h"
#include "arith/imul.h"
#include "arith/mul.h"
#include "arith/idiv.h"
#include "arith/div.h"

#include "logic/and.h"
#include "logic/or.h"
#include "logic/not.h"
#include "logic/xor.h"
#include "logic/sar.h"
#include "logic/shl.h"
#include "logic/shr.h"
#include "logic/shrd.h"

#include "string/rep.h"

#include "misc/misc.h"

#include "special/special.h"

#include "call/call.h"
#include "push/push.h"
#include "test/test.h"
#include "je/je.h"
#include "cmp/cmp.h"
#include "pop/pop.h"
#include "ret/ret.h"

#include "add/add.h"
#include "adc/adc.h"
#include "sub/sub.h"
#include "sbb/sbb.h"
#include "setcc/setcc.h"
#include "jmp/jmp.h"

#include "jcc/jcc.h"

#include "movs/movs.h"
#include "stos/stos.h"
#include "scas/scas.h"
#include "lods/lods.h"