#ifndef SHOW_HUGE_NUMBER
#define SHOW_HUGE_NUMBER

#include "../UseHugeNumber/Type/HugeFloat.h"
#include "../UseHugeNumber/Type/HugeInt.h"
#include "../UseHugeNumber/Type/HugeUnsignedInt.h"

extern void printHugeUnsignedInt (const HugeUnsignedInt* hugeUnsignedInt);
extern void printHugeInt         (const HugeInt* hugeInt);
extern void printHugeFloat       (const HugeFloat* hugeFloat);

#endif // !SHOW_HUGE_NUMBER
