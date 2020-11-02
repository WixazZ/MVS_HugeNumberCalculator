#include <stdio.h>
#include "ScanHugeNumber.h"

HugeInt* scanHugeInt (void) {
    char hugeIntInString[1000];
    if (scanf ("%s", hugeIntInString) == EOF)
        return NULL;
    return createHugeIntFromString (hugeIntInString);
}

HugeUnsignedInt* scanHugeUnsignedInt (void) {
    char hugeUnsignedIntInString[1000];
    if (scanf ("%s", hugeUnsignedIntInString) == EOF)
        return NULL;
    return createHugeUnsignedIntFromString (hugeUnsignedIntInString);
}