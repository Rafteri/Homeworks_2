//
// Created by Rafteri on 25.03.2016.
//

#ifndef AADS_LISTMERGER_H
#define AADS_LISTMERGER_H
struct Node {
    double value;
    Node *next = nullptr;
};

struct LinkedList {
    Node *first = nullptr;
    Node *last = nullptr;
};

struct StackElem {
    int rank = 0;
    LinkedList *list;
};

struct Stack {
    StackElem arr[32];
    int last = -1;
};

void ReadList (LinkedList *list);

void PrintList(LinkedList *list);

LinkedList *MergeSort(LinkedList *list);

#endif //AADS_LISTMERGER_H
