#ifndef OPERATOR_HUGE_UNSIGNED_INT
#define OPERATOR_HUGE_UNSIGNED_INT

#include "../Type/HugeUnsignedInt.h"
#include "../Type/HugeInt.h"

extern HugeUnsignedInt* addHugeUnsignedInt                 (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern HugeInt*         substractHugeUnsignedInt           (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern HugeUnsignedInt* multiplyHugeUnsignedInt            (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern HugeUnsignedInt* divideHugeUnsignedInt              (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern unsigned int     isHugeUnsignedIntStrictlySuperior  (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern unsigned int     isHugeUnsignedIntSuperior          (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern unsigned int     isHugeUnsignedIntEqual             (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern unsigned int     isHugeUnsignedIntInferior          (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern unsigned int     isHugeUnsignedIntStrictlyInferior  (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);
extern HugeUnsignedInt* createHugeUnsignedIntFromPowerOf10 (const HugeUnsignedInt* exponent);
extern void             incrementHugeUnsignedInt           (HugeUnsignedInt* hugeUnsignedInt);
extern void             decrementHugeUnsignedInt           (HugeUnsignedInt* hugeUnsignedInt);

#endif // !OPERATOR_HUGE_UNSIGNED_INT
