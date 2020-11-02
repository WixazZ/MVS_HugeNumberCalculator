#ifndef HUGE_FLOAT
#define HUGE_FLOAT

#include "HugeInt.h"

typedef struct HugeFloat {
    HugeInt* significand;
    HugeInt* exponent;
} HugeFloat;

extern HugeFloat* createHugeFloat              (void);
extern HugeFloat* createHugeFloatFromString    (const char* significandString, const char* exponentString);
extern HugeFloat* createHugeFloatFromHugeInts  (const HugeInt* significandHugeInt, const HugeInt* exponentSHugeInt);
extern HugeFloat* createHugeFloatFromHugeFloat (const HugeFloat* hugeFloat, const unsigned int size);
extern void       deleteHugeFloat              (const HugeFloat* hugeFloat);
extern int        getHugeFloatLength           (const HugeFloat* hugeFloat);

#endif // !HUGE_FLOAT
