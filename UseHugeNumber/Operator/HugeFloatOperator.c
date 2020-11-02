#include <stdio.h>
#include "HugeFloatOperator.h"

HugeFloat* addHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    HugeInt* exponentDifference = substractHugeInt (operand1->exponent, operand2->exponent);
    HugeFloat* result = createHugeFloat ();
    if (result != NULL) {
        HugeInt* tempOperand = createHugeInt ();
        if (tempOperand == NULL) {
            return NULL;
        }
        HugeInt* tempPowerOf10 = createHugeInt ();
        if (tempPowerOf10 == NULL) {
            return NULL;
        }
        tempPowerOf10->absoluteValue = createHugeUnsignedIntFromPowerOf10 (exponentDifference->absoluteValue);
        tempPowerOf10->sign = PLUS;
        if (exponentDifference->sign == PLUS) {
            tempOperand = multiplyHugeInt (operand1->significand, tempPowerOf10);
            result->significand = addHugeInt (tempOperand, operand2->significand);
            result->exponent = createHugeIntFromHugeInt (operand2->exponent, 0);
        } else {
            tempOperand = multiplyHugeInt (operand2->significand, tempPowerOf10);
            result->significand = addHugeInt (tempOperand, operand1->significand);
            result->exponent = createHugeIntFromHugeInt (operand1->exponent, 0);
        }
        deleteHugeInt (tempPowerOf10);
        deleteHugeInt (tempOperand);
        deleteHugeInt (exponentDifference);
    }
    simplifyHugeFloat (result);
    return result;
}

HugeFloat* substractHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    HugeFloat* result;
    HugeFloat* tmpOperand2 = createHugeFloatFromHugeFloat (operand2, 0);

    if (tmpOperand2 == NULL) {
        return NULL;
    }
    if (tmpOperand2->significand->sign == PLUS) {
        tmpOperand2->significand->sign = MINUS;
    } else {
        tmpOperand2->significand->sign = PLUS;
    }
    result = addHugeFloat (operand1, tmpOperand2);
    deleteHugeFloat (tmpOperand2);
    simplifyHugeFloat (result);
    return result;
}

HugeFloat* multiplyHugeFloat (const HugeFloat* operand1, const HugeFloat* operand2) {
    HugeFloat* result = createHugeFloat ();
    if (result != NULL) {
        result->significand = multiplyHugeInt (operand1->significand, operand2->significand);
        result->exponent = addHugeInt (operand1->exponent, operand2->exponent);
    }
    simplifyHugeFloat (result);
    return result;
}

HugeFloat* simplifyHugeFloat (HugeFloat* hugeFloat) {
    if (hugeFloat != NULL) {
        simplifyHugeInt (hugeFloat->significand);
        simplifyHugeInt (hugeFloat->exponent);
        char simplify = 1;
        while ((!isNodeEmpty (hugeFloat->significand->absoluteValue->end)) && simplify) {
            if ((hugeFloat->significand->absoluteValue->end->digit == 0)
                && (hugeFloat->significand->absoluteValue->end != hugeFloat->significand->absoluteValue->start)) {
                removeEndFromDoublyLinkedList (hugeFloat->significand->absoluteValue);
                incrementHugeUnsignedInt (hugeFloat->exponent->absoluteValue);
            } else {
                simplify = 0;
            }
        }
    }
    return hugeFloat;
}
