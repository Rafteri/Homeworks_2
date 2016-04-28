//
// Created by Rafteri on 25.03.2016.
//
#include "ListMerger.h"

int main() {
    LinkedList *list = new LinkedList;
    ReadList(list);

    list = MergeSort(list);

    PrintList(list);
    return 0;
}
