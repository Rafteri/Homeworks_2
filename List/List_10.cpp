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

void ReadList(LinkedList *list) {
    double value;
    while (cin.peek() != '\n') {
        cin >> value;
        AddToEnd(list, value);
    }
    cin.get();
}

bool CheckOrder(LinkedList *list) {
    Node *node = list->first;
    if (node == NULL || node->next == NULL) {
        return true;
    }
    else if (node->value > node->next->value) {
        node = node->next;
        while (node->next != NULL) {
            if (node->value < node->next->value) {
                return false;
            }
            node = node->next;
        }
        return true;
    }
    else {
        node = node->next;
        while (node->next != NULL) {
            if (node->value > node->next->value) {
                return false;
            }
            node = node->next;
        }
        return true;
    }
}

int main () {
    LinkedList *list = new LinkedList;
    cout << "Enter elements of list" << endl;
    ReadList(list);

    if (CheckOrder(list)) {
        cout << "List is ordered.";
    }
    else {
        cout << "List isn't ordered.";
    }

    return 0;
}