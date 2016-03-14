//
// Created by Rafteri on 02.03.2016.
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

void AddToEnd(LinkedList *list, double a) {
    Node *node = new Node;
    node->value = a;
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

void ReadList(LinkedList *list) {
    double num;
    while (cin.peek() != '\n') {
        cin >> num;
        AddToEnd(list, num);
    }
    cin.get();
}

void PrintList(LinkedList *list) {
    Node *node = list->first;
    while (node != NULL) {
        cout << node->value << ' ';
        node = node->next;
    }
}

LinkedList *PlusList(LinkedList *list) {
    LinkedList *PList = new LinkedList;

    Node *node = list->first;

    while (node != NULL) {
        if (node->value >= 0) {
            AddToEnd(PList, node->value);
        }
        node = node->next;
    }

    return PList;
}

int main() {
    LinkedList *list = new LinkedList;
    cout << "Enter elements of list: ";
    ReadList(list);

    LinkedList *PList = PlusList(list);

    cout << "Plus list:" << endl;
    PrintList(PList);
    return 0;
}
