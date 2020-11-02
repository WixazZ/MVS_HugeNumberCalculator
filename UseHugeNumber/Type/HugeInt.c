#include <stdio.h>
#include <stdlib.h>
#include "HugeInt.h"

HugeInt* createHugeInt (void) {
    HugeInt* hugeInt = malloc (sizeof (HugeInt));

    if (hugeInt != NULL) {
        HugeUnsignedInt* absoluteValue = createHugeUnsignedInt ();
        hugeInt->absoluteValue = absoluteValue;
        hugeInt->sign = PLUS;
    }

    return hugeInt;
}

HugeInt* createHugeIntFromString (const char* digitString) {
    HugeInt* hugeInt = createHugeInt ();

    if (hugeInt != NULL) {
        int explicitSign = 0;
        switch (*digitString) {
        case '-':
            hugeInt->sign = MINUS;
            explicitSign++;
            break;
        case '+':
            explicitSign++;
        default:
            hugeInt->sign = PLUS;
        }

        hugeInt->absoluteValue = createHugeUnsignedIntFromString (digitString + explicitSign);
    }

    return hugeInt;
}

HugeInt* createHugeIntFromHugeInt (const HugeInt* hugeInt, const unsigned int size) {
    HugeInt* hugeIntCopy = createHugeInt ();
    if ((hugeIntCopy != NULL) && (hugeInt != NULL)) {
        hugeIntCopy->absoluteValue = createHugeUnsignedIntFromHugeUnsignedInt (hugeInt->absoluteValue, size);
        hugeIntCopy->sign = hugeInt->sign;
    }
    return hugeIntCopy;
}

void deleteHugeInt (HugeInt* hugeInt) {
    if (hugeInt != NULL) {
        deleteHugeUnsignedInt (hugeInt->absoluteValue);
        free (hugeInt);
    }
}

int getHugeIntLength (const HugeInt* hugeInt) {
    if (hugeInt != NULL) {
        return getHugeUnsignedIntLength (hugeInt->absoluteValue) + 1;
    }
    return 0;
}

HugeInt* simplifyHugeInt (HugeInt* hugeInt) {
    if (hugeInt != NULL) {
        simplifyHugeUnsignedInt (hugeInt->absoluteValue);
    }
    return hugeInt;
}