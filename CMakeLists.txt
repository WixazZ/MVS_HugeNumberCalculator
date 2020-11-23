project(Huffman_Coding)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(SRCS
        main.c
        DataTypes/DoublyLinkedList.c
        IHMHugeNumber/ScanHugeNumber.c
        IHMHugeNumber/ShowHugeNumber.c
        UseHugeNumber/Operator/HugeFloatOperator.c
        UseHugeNumber/Operator/HugeIntOperator.c
        UseHugeNumber/Operator/HugeUnsignedIntOperator.c
        UseHugeNumber/Type/HugeFloat.c
        UseHugeNumber/Type/HugeInt.c
        UseHugeNumber/Type/HugeUnsignedInt.c)

set(HEADERS
        DataTypes/DoublyLinkedList.h
        IHMHugeNumber/ScanHugeNumber.h
        IHMHugeNumber/ScanHugeNumber.h
        UseHugeNumber/Operator/HugeFloatOperator.h
        UseHugeNumber/Operator/HugeIntOperator.h
        UseHugeNumber/Operator/HugeUnsignedIntOperator.h
        UseHugeNumber/Type/HugeFloat.h
        UseHugeNumber/Type/HugeInt.h
        UseHugeNumber/Type/HugeUnsignedInt.h)


add_executable(Huffman_Coding ${SRCS} ${HEADERS})