#ifndef OPERATOR_HUGE_FLOAT
#define OPERATOR_HUGE_FLOAT

#include "HugeIntOperator.h"
#include "HugeUnsignedIntOperator.h"
#include "../Type/HugeFloat.h"

extern HugeFloat* addHugeFloat       (const HugeFloat* operand1, const HugeFloat* operand2);
extern HugeFloat* substractHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2);
extern HugeFloat* multiplyHugeFloat  (const HugeFloat* operand1, const HugeFloat* operand2);
extern HugeFloat* simplifyHugeFloat  (HugeFloat* hugeFloat);

#endif // !OPERATOR_HUGE_FLOAT