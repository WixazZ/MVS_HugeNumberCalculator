#include <stdio.h>
#include <stdlib.h>
#include "HugeFloat.h"

HugeFloat* createHugeFloat (void) {
    HugeFloat* hugeFloat = malloc (sizeof (HugeFloat));

    if (hugeFloat != NULL) {
        hugeFloat->significand = createHugeInt ();
        hugeFloat->exponent = createHugeInt ();
    }

    return hugeFloat;
}

HugeFloat* createHugeFloatFromString (const char* significandString, const char* exponentString) {
    HugeFloat* hugeFloat = createHugeFloat ();

    if (hugeFloat != NULL) {
        hugeFloat->significand = createHugeIntFromString (significandString);
        hugeFloat->exponent = createHugeIntFromString (exponentString);
    }

    return hugeFloat;
}

HugeFloat* createHugeFloatFromHugeInts (const HugeInt* significandHugeInt, const HugeInt* exponentSHugeInt) {
    HugeFloat* hugeFloat = createHugeFloat ();

    if (hugeFloat != NULL) {
        hugeFloat->significand = (HugeInt*) significandHugeInt;
        hugeFloat->exponent = (HugeInt*) exponentSHugeInt;
    }

    return hugeFloat;
}

HugeFloat* createHugeFloatFromHugeFloat (const HugeFloat* hugeFloat, const unsigned int size) {
    HugeFloat* hugeFloatCopy = createHugeFloat ();
    if ((hugeFloatCopy != NULL) && (hugeFloat != NULL)) {
        hugeFloatCopy->significand = createHugeIntFromHugeInt (hugeFloat->significand, size);
        hugeFloatCopy->exponent = createHugeIntFromHugeInt (hugeFloat->exponent, 0);
    }
    return hugeFloatCopy;
}

void deleteHugeFloat (const HugeFloat* hugeFloat) {
    if (hugeFloat != NULL) {
        deleteHugeInt (hugeFloat->significand);
        deleteHugeInt (hugeFloat->exponent);
    }
}

int getHugeFloatLength (const HugeFloat* hugeFloat) {
    if (hugeFloat != NULL) {
        return getHugeIntLength (hugeFloat->significand) + getHugeIntLength (hugeFloat->exponent);
    }
    return 0;
}
