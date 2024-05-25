#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
    Data data1 = { "Adam", "Nowak", 19 };
    Data data2 = { "Dawid", "Kowalski", 23 };
    DoubleLinkedList list(data1);
    list.pushBack(data2);
    DoubleLinkedList list2 = list;
}
