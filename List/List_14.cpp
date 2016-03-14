//
// Created by Rafteri on 06.03.2016.
//
#include <iostream>
using namespace std;

struct Node {
    double value;
    Node *next = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

void AddToEnd (LinkedList *list, double value) {
    Node *node = new Node;
    node->value = value;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    }
    else {
        list->last->next = node;
        list->last = node;
    }
}

LinkedList *ReadList () {
    LinkedList *list = new LinkedList;
    cout << "Enter elements of list" << endl;
    double value;
    while (cin.peek() != '\n') {
        cin >> value;
        AddToEnd(list, value);
    }
    cin.get();
    return list;
}

void PrintList(LinkedList *list) {
    Node *node = list->first;
    while (node != NULL) {
        cout << node->value << ' ';
        node = node->next;
    }
}

void Reverse(LinkedList *list){
    Node *node = list->first;
    Node *PrevNode, *CurNodeNext = NULL;
    while (node != NULL) {
        PrevNode = node;
        node = node->next;
        PrevNode->next = CurNodeNext;
        CurNodeNext = PrevNode;
    }
    list->first = PrevNode;

}

int main() {
    LinkedList *list = ReadList();

    Reverse(list);

    PrintList(list);
    return 0;
}