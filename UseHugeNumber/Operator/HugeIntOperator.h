#ifndef OPERATOR_HUGE_INT
#define OPERATOR_HUGE_INT

#include "../Type/HugeInt.h"
#include "HugeUnsignedIntOperator.h"

extern HugeInt* addHugeInt       (const HugeInt* operand1, const HugeInt* operand2);
extern HugeInt* substractHugeInt (const HugeInt* operand1, const HugeInt* operand2);
extern HugeInt* multiplyHugeInt  (const HugeInt* operand1, const HugeInt* operand2);
extern HugeInt* divideHugeInt    (const HugeInt* operand1, const HugeInt* operand2);

#endif // !OPERATOR_HUGE_INT
