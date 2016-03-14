//
// Created by Rafteri on 04.03.2016.
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

void ReadList (LinkedList *list) {
    double value;
    while (cin.peek() != '\n') {
        cin >> value;
        AddToEnd(list, value);
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

void AddTail(LinkedList *list, Node *node) {
    while (node != NULL) {
        AddToEnd(list, node->value);
        node = node->next;
    }
}

Node *Next(LinkedList *list, Node *node) {
    do {
        node = node->next;
    } while (node != NULL && list->last->value == node->value);
    return node;
}

LinkedList *Association(LinkedList *list1, LinkedList *list2) {
    LinkedList *list = new LinkedList;
    Node *node1 = list1->first;
    Node *node2 = list2->first;
    while (node1 != NULL && node2 != NULL) {
        if (node1->value > node2->value) {
            AddToEnd(list, node2->value);
            node2 = Next(list, node2);
        }
        else if (node1->value < node2->value) {
            AddToEnd(list, node1->value);
            node1 = Next(list, node1);
        }
        else {
            AddToEnd(list, node1->value);
            node1 = Next(list, node1);
            node2 = Next(list, node2);
        }
    }
    AddTail(list, node1);
    AddTail(list, node2);
    return list;
}

int main() {
    LinkedList *list1 = new LinkedList;
    cout << "Enter elements of first list" << endl;
    ReadList(list1);

    LinkedList *list2 = new LinkedList;
    cout << "Enter elements of second list" << endl;
    ReadList(list2);

    LinkedList *list = Association(list1, list2);

    cout << "Elements of association:" << endl;
    PrintList(list);
    return 0;
}
