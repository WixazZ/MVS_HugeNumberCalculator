#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

#define START_ASCII_DIGIT 48
#define END_ASCII_DIGIT 58
#define MAX_DIGIT_STRING_SIZE 512

static Node* createNode (const Digit digit) {
    Node* node = malloc (sizeof (Node));
    if (node != NULL) {
        node->digit = digit;
        node->next = NULL;
        node->previous = NULL;
    }
    return node;
};

static int addDigit (DoublyLinkedList* doublyLinkedList, const Digit digit, const unsigned short startOrEnd) {
    int executionSucceed = 0;
    Node* node = createNode (digit);

    if (node == NULL) {
        executionSucceed = 0;
    } else if (isNodeEmpty (doublyLinkedList->start)) {
        doublyLinkedList->start = node;
        doublyLinkedList->end = node;
        executionSucceed = 1;
    } else {
        if (startOrEnd == 0) {
            doublyLinkedList->start->previous = node;
            node->next = doublyLinkedList->start;
            doublyLinkedList->start = node;
        } else {
            doublyLinkedList->end->next = node;
            node->previous = doublyLinkedList->end;
            doublyLinkedList->end = node;
        }
        executionSucceed = 1;
    }
    return executionSucceed;
}

static Digit charToDigit (const char digitChar) {
    if ((digitChar < START_ASCII_DIGIT) || (digitChar > END_ASCII_DIGIT)) {
        return 0;
    } else {
        return digitChar - START_ASCII_DIGIT;
    }
}

int addDigitAtStart (DoublyLinkedList* doublyLinkedList, const Digit digit) {
    return addDigit (doublyLinkedList, digit, 0);
}

int addDigitAtEnd (DoublyLinkedList* doublyLinkedList, const Digit digit) {
    return addDigit (doublyLinkedList, digit, 1);
}

static void deleteNode (Node* node) {
    if (!isNodeEmpty (node->previous)) {
        node->previous->next = node->next;
    }
    if (!isNodeEmpty (node->next)) {
        node->next->previous = node->previous;
    }
    free (node);
}

int isNodeEmpty (const Node* node) {
    return node == NULL;
}

DoublyLinkedList* createDoublyLinkedList (void) {
    DoublyLinkedList* doublyLinkedList = malloc (sizeof (DoublyLinkedList));
    if (doublyLinkedList != NULL) {
        doublyLinkedList->start = NULL;
        doublyLinkedList->end = NULL;
    }
    return doublyLinkedList;
}

DoublyLinkedList* createDoublyLinkedListFromString (const char* digitString) {
    DoublyLinkedList* doublyLinkedList = createDoublyLinkedList ();

    if (doublyLinkedList != NULL) {
        for (unsigned int i = 0; i < strnlen (digitString, MAX_DIGIT_STRING_SIZE); i++) {
            addDigitAtEnd (doublyLinkedList, charToDigit (*(digitString + i)));
        }
    }

    return doublyLinkedList;
}

char digitToChar (const Digit digit) {
    if (digit > 9) {
        return 'E';
    } else {
        return digit + START_ASCII_DIGIT;
    }
}

void deleteDoublyLinkedList (DoublyLinkedList* doublyLinkedList) {
    if (doublyLinkedList != NULL) {
        while (doublyLinkedList->start != NULL) {
            Node* node;
            node = doublyLinkedList->start;
            doublyLinkedList->start = doublyLinkedList->start->next;
            deleteNode (node);
        }
        free (doublyLinkedList);
    }
}

int getDoublyLinkedListLength (const DoublyLinkedList* doublyLinkedList) {
    Node* node;
    int doublyLinkedListLength = 0;
    if (doublyLinkedList != NULL) {
        node = doublyLinkedList->start;
        while (!isNodeEmpty (node)) {
            doublyLinkedListLength++;
            node = node->next;
        }
    }
    return doublyLinkedListLength;
}

void removeStartFromDoublyLinkedList (DoublyLinkedList* doublyLinkedList) {
    if (doublyLinkedList->start != NULL) {
        Node* node;
        node = doublyLinkedList->start;
        doublyLinkedList->start = doublyLinkedList->start->next;
        if (node == doublyLinkedList->end) {
            doublyLinkedList->end = NULL;
        }
        deleteNode (node);
    }
}

void removeEndFromDoublyLinkedList (DoublyLinkedList* doublyLinkedList) {
    if (doublyLinkedList->end != NULL) {
        Node* node;
        node = doublyLinkedList->end;
        doublyLinkedList->end = doublyLinkedList->end->previous;
        if (node == doublyLinkedList->start) {
            doublyLinkedList->start = NULL;
        }
        deleteNode (node);
    }
}

Digit getDigitByPlaceFromStart (const DoublyLinkedList* doublyLinkedList, unsigned int place) {
    Digit result = 'E';

    if (doublyLinkedList->start != NULL) {
        Node* node;
        node = doublyLinkedList->start;
        for (unsigned int i = 0; (i < place) && !isNodeEmpty (node); i++) {
            node = node->next;
        }
        if (!isNodeEmpty (node)) {
            result = node->digit;
        }
    }
    return result;
}
