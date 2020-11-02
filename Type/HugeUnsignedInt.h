#ifndef HUGE_UNSIGNED_INT
#define HUGE_UNSIGNED_INT

#include "../../DataTypes/DoublyLinkedList.h"

typedef DoublyLinkedList HugeUnsignedInt;

extern HugeUnsignedInt* createHugeUnsignedInt                    (void);
extern HugeUnsignedInt* createHugeUnsignedIntFromString          (const char* digitString);
extern HugeUnsignedInt* createHugeUnsignedIntFromHugeUnsignedInt (const HugeUnsignedInt* hugeUnsignedInt, const unsigned int size);
extern void             deleteHugeUnsignedInt                    (HugeUnsignedInt* hugeUnsignedInt);
extern int              getHugeUnsignedIntLength                 (const HugeUnsignedInt* hugeUnsignedInt);
extern HugeUnsignedInt* simplifyHugeUnsignedInt                  (HugeUnsignedInt* hugeUnsignedInt);

#endif // !HUGE_UNSIGNED_INT
