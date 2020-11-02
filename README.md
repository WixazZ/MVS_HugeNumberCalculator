# HugeNumberCalculator
A calculator for handling huge numbers.

### This version contains all functions wtih implemented code, but there's no doxygen documention
* .H files only contain function signatures
* .C files only contain implemented code

![Package Diagram](PackageDiagram.png)

### HugeNumberCalculator architecture :
* \DataTypes
  * DoublyLinked.h
    * `typedef unsigned short Digit;`
    * `typedef struct Node;`
    * `typedef struct DoublyLinkedList;`
    * `int addDigitAtEnd (DoublyLinkedList* doublyLinkedList, Digit digit);`
    * `int addDigitAtStart (DoublyLinkedList* doublyLinkedList, Digit digit);`
    * `DoublyLinkedList* createDoublyLinkedList (void);`
    * `DoublyLinkedList* createDoublyLinkedListFromString (char* digitString);`
    * `void deleteDoublyLinkedList (DoublyLinkedList* doublyLinkedList);`
    * `char digitToChar (Digit digit);`
    * `Digit getDigitByPlaceFromStart (DoublyLinkedList* doublyLinkedList, unsigned int place);`
    * `int getDoublyLinkedListLength (DoublyLinkedList* doublyLinkedList);`
    * `int isNodeEmpty (Node* node);`
    * `void removeEndFromDoublyLinkedList (DoublyLinkedList* doublyLinkedList);`
    * `void removeStartFromDoublyLinkedList (DoublyLinkedList* doublyLinkedList);`
  * DoublyLinked.c
    * `Digit charToDigit (char digitChar);`
    * `Node* createNode (Digit digit);`
    * `void deleteNode (Node* node);`
* \UseHugeNumber
  * \Operator
    * HugeFloatOperator.h
      * `HugeFloat* addHugeFloat (HugeFloat* operand1, HugeFloat* operand2);`
      * `HugeFloat* substractHugeFloat (HugeFloat* operand1, HugeFloat* operand2);`
      * `HugeFloat* multiplyHugeFloat (HugeFloat* operand1, HugeFloat* operand2);`
      * `HugeFloat* simplifyHugeFloat (HugeFloat* hugeFloat);`
    * HugeFloatOperator.c
    * HugeIntOperator.h
      * `HugeInt* addHugeInt (HugeInt* operand1, HugeInt* operand2);`
      * `HugeInt* substractHugeInt (HugeInt* operand1, HugeInt* operand2);`
      * `HugeInt* multiplyHugeInt (HugeInt* operand1, HugeInt* operand2);`
      * `HugeInt* divideHugeInt (HugeInt* operand1, HugeInt* operand2);`
    * HugeIntOperator.c
    * HugeUnsignedIntOperator.h
      * `HugeUnsignedInt* addHugeUnsignedInt (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
      * `HugeUnsignedInt* createHugeUnsignedIntFromPowerOf10 (HugeUnsignedInt* exponent);`
      * `void decrementHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt);`
      * `HugeUnsignedInt* divideHugeUnsignedInt (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
      * `void incrementHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt);`
      * `unsigned int isHugeUnsignedIntStrictlySuperior (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
      * `unsigned int isHugeUnsignedIntSuperior (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
      * `unsigned int isHugeUnsignedIntEqual (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
      * `unsigned int isHugeUnsignedIntInferior (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
      * `unsigned int isHugeUnsignedIntStrictlyInferior (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
      * `HugeInt* substractHugeUnsignedInt (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
      * `ugeUnsignedInt* multiplyHugeUnsignedInt (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
    * HugeUnsignedIntOperator.c
      * `unsigned int compareHugeUnsignedInts (HugeUnsignedInt* operand1, HugeUnsignedInt* operand2);`
  * \Type
    * HugeFloat.h
      * `typedef struct HugeFloat;`
      * `HugeFloat* createHugeFloat (void);`
      * `HugeFloat* createHugeFloatFromString (char* significandString, char* exponentString);`
      * `HugeFloat* createHugeFloatFromHugeInts (HugeInt* significandHugeInt, HugeInt* exponentSHugeInt);`
      * `HugeFloat* createHugeFloatFromHugeFloat (HugeFloat* hugeFloat, unsigned int size);`
      * `void deleteHugeFloat (HugeFloat* hugeFloat);`
      * `int getHugeFloatLength (HugeFloat* hugeFloat);`
    * HugeFloat.c
    * HugeInt.h
      * `typedef enum Sign;`
      * `typedef struct HugeInt;`
      * `HugeInt* createHugeInt (void);`
      * `HugeInt* createHugeIntFromString (char* digitString);`
      * `HugeInt* createHugeIntFromHugeInt (HugeInt* hugeInt, unsigned int size);`
      * `void deleteHugeInt (HugeInt* hugeInt);`
      * `int getHugeIntLength (HugeInt* hugeInt);`
      * `HugeInt* simplifyHugeInt (HugeInt* hugeInt);`
    * HugeInt.c
    * HugeUnsignedInt.h
      * `HugeUnsignedInt* createHugeUnsignedInt (void);`
      * `HugeUnsignedInt* createHugeUnsignedIntFromString (char* digitString);`
      * `HugeUnsignedInt* createHugeUnsignedIntFromHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt, unsigned int size);`
      * `void deleteHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt);`
      * `int getHugeUnsignedIntLength (HugeUnsignedInt* hugeUnsignedInt);`
      * `HugeUnsignedInt* simplifyHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt);`
    * HugeUnsignedInt.c
* \IHMHugeNumber
  * ScanHugeNumber.h
    * `HugeInt* scanHugeInt (void);`
    * `HugeInt* scanHugeUnsignedInt (void);`
  * ScanHugeNumber.h
  * ShowHugeNumber.h
    * `void printHugeUnsignedInt (HugeUnsignedInt* hugeUnsignedInt);`
    * `void printHugeInt (HugeInt* hugeInt);`
    * `void printHugeFloat (HugeFloat* hugeFloat);`
  * ShowHugeNumber.h
    * `char* HugeUnsignedIntToString (HugeUnsignedInt* hugeUnsignedInt);`
    * `char* HugeIntToString (HugeInt* hugeInt);`
    * `* HugeFloatToString (HugeFloat* hugeFloat);`
