#include <stdio.h>
#include <stdlib.h>
#include "HugeUnsignedIntOperator.h"

#define HUGE_NUMBER_SUPERIOR 1
#define HUGE_NUMBER_EQUAL 2
#define HUGE_NUMBER_INFERIOR 3

static unsigned int compareHugeUnsignedInts (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2);

HugeUnsignedInt* addHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    HugeUnsignedInt* result = createHugeUnsignedInt ();

    if (result != NULL) {
        Node* node1 = operand1->end;
        Node* node2 = operand2->end;
        Digit carry = 0;
        while (!isNodeEmpty (node1) || !isNodeEmpty (node2)) {
            Digit digitNode1 = isNodeEmpty (node1) ? 0 : node1->digit;
            Digit digitNode2 = isNodeEmpty (node2) ? 0 : node2->digit;
            Digit digitResult = (digitNode1 + digitNode2 + carry) % 10;
            carry = (digitNode1 + digitNode2 + carry) / 10;
            addDigitAtStart (result, digitResult);
            if (!isNodeEmpty (node1)) {
                node1 = node1->previous;
            }
            if (!isNodeEmpty (node2)) {
                node2 = node2->previous;
            }
        }
        if (carry > 0) {
            addDigitAtStart (result, carry);
        }
    }
    return result;
}

HugeInt* substractHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    HugeInt* result = createHugeInt ();

    if (result != NULL) {
        Node* node1;
        Node* node2;
        Digit carry = 0;

        if (isHugeUnsignedIntSuperior (operand1, operand2)) {
            node1 = operand1->end;
            node2 = operand2->end;
            result->sign = PLUS;
        } else {
            node1 = operand2->end;
            node2 = operand1->end;
            result->sign = MINUS;
        }

        while (!isNodeEmpty (node1) || !isNodeEmpty (node2)) {
            Digit digitResult;
            Digit digitNode1 = isNodeEmpty (node1) ? 0 : node1->digit;
            Digit digitNode2 = isNodeEmpty (node2) ? 0 : node2->digit;
            if (((digitNode1 == 0) && (carry > 0)) || ((digitNode1 - carry) < digitNode2)) {
                digitNode1 += 10 - carry;
                carry = 1;
            } else {
                digitNode1 -= carry;
                carry = 0;
            }
            digitResult = (digitNode1 - digitNode2) % 10;
            addDigitAtStart (result->absoluteValue, digitResult);
            if (!isNodeEmpty (node1)) {
                node1 = node1->previous;
            }
            if (!isNodeEmpty (node2)) {
                node2 = node2->previous;
            }
        }
    }
    simplifyHugeInt (result);
    return result;
}

HugeUnsignedInt* multiplyHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    if ((operand1 == NULL) || (operand2 == NULL)) {
        return NULL;
    }
    HugeUnsignedInt* result = createHugeUnsignedInt ();
    if (result == NULL) {
        return NULL;
    }
    unsigned int column = 0;
    for (Node* node2 = operand2->end; !isNodeEmpty (node2); node2 = node2->previous, column++) {
        Digit carry = 0;
        HugeUnsignedInt* temp = createHugeUnsignedInt ();
        if (temp == NULL) {
            return NULL;
        }
        for (Node* node1 = operand1->end; !isNodeEmpty (node1); node1 = node1->previous) {
           Digit digitNode1 = node1->digit;
            Digit digitNode2 = node2->digit;
            Digit digitResult = ((digitNode1 * digitNode2) + carry) % 10;
            carry = ((digitNode1 * digitNode2) + carry) / 10;
            addDigitAtStart (temp, digitResult);
        }
        if (carry > 0) {
            addDigitAtStart (temp, carry);
        }
        for (unsigned int i = 0; i < column; i++) {
            addDigitAtEnd (temp, 0);
        }
        HugeUnsignedInt* tmpResult = addHugeUnsignedInt (result, temp);
        deleteHugeUnsignedInt (result);
        result = tmpResult;
        deleteHugeUnsignedInt (temp);
    }

    simplifyHugeUnsignedInt (result);
    return result;
}

HugeUnsignedInt* divideHugeUnsignedInt (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    if ((operand1 == NULL) || (operand2 == NULL)) {
        return NULL;
    }
    HugeUnsignedInt* result = createHugeUnsignedIntFromString ("0");
    if (result == NULL) {
        return NULL;
    }
    unsigned int operand1Length = getHugeUnsignedIntLength (operand1);
    unsigned int operand2Length = getHugeUnsignedIntLength (operand2);
    unsigned int place = operand2Length;
    HugeInt* remainder = createHugeInt ();
    remainder->absoluteValue = createHugeUnsignedIntFromHugeUnsignedInt (operand1, operand2Length);
    while (place <= operand1Length) {
        HugeInt* keepForDelete;
        HugeUnsignedInt* quotient;
        HugeUnsignedInt* multiplyResult;
        quotient = createHugeUnsignedIntFromString ("1");
        multiplyResult = multiplyHugeUnsignedInt (quotient, operand2);
        unsigned int compareResult = compareHugeUnsignedInts (remainder->absoluteValue, multiplyResult);
        while (compareResult == HUGE_NUMBER_SUPERIOR) {
            deleteHugeUnsignedInt (multiplyResult);
            incrementHugeUnsignedInt (quotient);
            multiplyResult = multiplyHugeUnsignedInt (quotient, operand2);
            compareResult = compareHugeUnsignedInts (remainder->absoluteValue, multiplyResult);
        }
        keepForDelete = remainder;
        if (compareResult == HUGE_NUMBER_INFERIOR) {
            decrementHugeUnsignedInt (quotient);
            deleteHugeUnsignedInt (multiplyResult);
            multiplyResult = multiplyHugeUnsignedInt (quotient, operand2);
        }
        addDigitAtEnd (result, quotient->start->digit);
        remainder = substractHugeUnsignedInt (remainder->absoluteValue, multiplyResult);

        deleteHugeUnsignedInt (multiplyResult);
        deleteHugeInt (keepForDelete);
        deleteHugeUnsignedInt (quotient);
        if (place < operand1Length) {
            addDigitAtEnd (remainder->absoluteValue, getDigitByPlaceFromStart (operand1, place));
            simplifyHugeInt (remainder);
        }
        place++;
    }
    simplifyHugeUnsignedInt (result);
    return result;
}

unsigned int compareHugeUnsignedInts (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    if ((operand1 == NULL) && (operand2 == NULL)) {
        return HUGE_NUMBER_EQUAL;
    }
    if (operand1 == NULL) {
        return HUGE_NUMBER_INFERIOR;
    }
    if (operand2 == NULL) {
        return HUGE_NUMBER_SUPERIOR;
    }
    unsigned int operand1Length = getHugeUnsignedIntLength (operand1);
    unsigned int operand2Length = getHugeUnsignedIntLength (operand2);

    if (operand1Length > operand2Length) {
        return HUGE_NUMBER_SUPERIOR;
    }
    if (operand1Length < operand2Length) {
        return HUGE_NUMBER_INFERIOR;
    }
    Node* nodeOperand1 = operand1->start;
    Node* nodeOperand2 = operand2->start;
    int found = 0;
    while ((!isNodeEmpty (nodeOperand1)) && (found == 0)) {
        if (nodeOperand1->digit > nodeOperand2->digit) {
            found = 1;
        }
        if (nodeOperand1->digit < nodeOperand2->digit) {
            found = -1;
        }
        nodeOperand1 = nodeOperand1->next;
        nodeOperand2 = nodeOperand2->next;
    }
    switch (found) {
    case 1:
        return HUGE_NUMBER_SUPERIOR;
    case -1:
        return HUGE_NUMBER_INFERIOR;
    default:
        return HUGE_NUMBER_EQUAL;
    }
}

unsigned int isHugeUnsignedIntStrictlySuperior (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return compareHugeUnsignedInts (operand1, operand2) == HUGE_NUMBER_SUPERIOR;
}

unsigned int isHugeUnsignedIntSuperior (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    unsigned int result = compareHugeUnsignedInts (operand1, operand2);

    return (result == HUGE_NUMBER_SUPERIOR) || (result == HUGE_NUMBER_EQUAL);
}

unsigned int isHugeUnsignedIntEqual (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return compareHugeUnsignedInts (operand1, operand2) == HUGE_NUMBER_EQUAL;
}

unsigned int isHugeUnsignedIntInferior (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    unsigned int result = compareHugeUnsignedInts (operand1, operand2);

    return (result == HUGE_NUMBER_INFERIOR) || (result == HUGE_NUMBER_EQUAL);
}

unsigned int isHugeUnsignedIntStrictlyInferior (const HugeUnsignedInt* operand1, const HugeUnsignedInt* operand2) {
    return compareHugeUnsignedInts (operand1, operand2) == HUGE_NUMBER_INFERIOR;
}

HugeUnsignedInt* createHugeUnsignedIntFromPowerOf10 (const HugeUnsignedInt* exponent) {
    HugeUnsignedInt* hugeUnsignedInt = createHugeUnsignedInt ();
    if ((hugeUnsignedInt != NULL)) {
        addDigitAtStart (hugeUnsignedInt, 1);
        HugeUnsignedInt* i;
        for (i = createHugeUnsignedIntFromString ("0"); isHugeUnsignedIntStrictlyInferior (i, exponent); incrementHugeUnsignedInt (i)) {
            addDigitAtEnd (hugeUnsignedInt, 0);
        }
        deleteHugeUnsignedInt (i);
    }
    return hugeUnsignedInt;
}

void incrementHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt) {
    if (hugeUnsignedInt != NULL) {
        HugeUnsignedInt* hugeUnsignedOne = createHugeUnsignedIntFromString ("1");
        HugeUnsignedInt* temp = addHugeUnsignedInt (hugeUnsignedInt, hugeUnsignedOne);
        while (hugeUnsignedInt->start != NULL) {
            hugeUnsignedInt->start = hugeUnsignedInt->start->next;
         }
        hugeUnsignedInt->start = temp->start;
        hugeUnsignedInt->end = temp->end;
        free (temp);
    }
}

void decrementHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt) {
    if (hugeUnsignedInt != NULL) {
        HugeUnsignedInt* hugeUnsignedOne = createHugeUnsignedIntFromString ("1");
        HugeInt* temp = substractHugeUnsignedInt (hugeUnsignedInt, hugeUnsignedOne);
        while (hugeUnsignedInt->start != NULL) {
            hugeUnsignedInt->start = hugeUnsignedInt->start->next;
        }
        hugeUnsignedInt->start = temp->absoluteValue->start;
        hugeUnsignedInt->end = temp->absoluteValue->end;
        free (temp);
    }
}
