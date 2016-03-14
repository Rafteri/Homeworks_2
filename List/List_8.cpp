//
// Created by Rafteri on 02.03.2016.
//
#include <iostream>
using namespace std;

struct Node {
    double value;
    Node *next = NULL;
    Node *prev = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

void AddToEnd(LinkedList *list, double value) {
    Node *node = new Node;
    node->value = value;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    }
    else {
        node->prev = list->last;
        list->last->next = node;
    }
    list->last = node;
}

void ReadList(LinkedList *list) {
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

void swap(LinkedList *list, Node *prevNode, Node *curNode, Node *nextNode) {
    if (nextNode == NULL) {
        prevNode->next = NULL;
        list->last = prevNode;
    }
    else {
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }
    curNode->next = prevNode;
    if (prevNode->prev == NULL) {
        curNode->prev = NULL;
        list->first = curNode;
        prevNode->prev = curNode;
    }
    else {
        prevNode->prev->next = curNode;
        curNode->prev = prevNode->prev;
        prevNode->prev = curNode;
    }
}

void InclusionSort(LinkedList *list) {

    Node *node = list->first->next;
    while (node != NULL) {
        Node *prevNode = node->prev;
        Node *curNode = node;
        Node *nextNode = node->next;
        while (prevNode != NULL && prevNode->value > curNode->value) {
            swap(list, prevNode, curNode, nextNode);

            nextNode = prevNode;
            prevNode = curNode->prev;
        }
        node = node->next;
    }


}

int main() {
    LinkedList *list = new LinkedList;
    cout << "Enter elements of list" << endl;
    ReadList(list);

    InclusionSort(list);
    cout << "Sorted list:" << endl;
    PrintList(list);

    return 0;
}
