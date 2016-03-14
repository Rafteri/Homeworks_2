//
// Created by Rafteri on 02.03.2016.
//
#include <iostream>
#include <tuple>

using namespace std;

struct Node1 {
    int value;
    Node1 *next = NULL;
};

struct Node2 {
    int value;
    Node2 *next = NULL;
    Node2 *prev = NULL;
};

struct LinkedList1 {
    Node1 *first = NULL;
    Node1 *last = NULL;
};

struct LinkedList2 {
    Node2 *first = NULL;
    Node2 *last = NULL;
};

void AddToEndNode1(LinkedList1 *list, int a) {
    Node1 *node = new Node1;
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

void AddToEndNode2(LinkedList2 *list2, int a) {
    Node2 *node = new Node2;
    node->value = a;
    node->next = NULL;
    if (list2->first == NULL) {
        list2->first = node;
        list2->last = node;
        node->prev = NULL;
    }
    else {
        node->prev = list2->last;
        list2->last->next = node;
        list2->last = node;
    }
}

LinkedList1 *ReadList1() {
    LinkedList1 *list = new LinkedList1;
    int num;
    while (cin.peek() != '\n') {
        cin >> num;
        AddToEndNode1(list, num);
    }
    cin.get();
    return list;
}

LinkedList2 ReadList2() {
    LinkedList2 *list = new LinkedList2;
    int num;
    while (cin.peek() != '\n') {
        cin >> num;
        AddToEndNode2(list, num);
    }
    cin.get();
    return list;
}

void PrintList2(LinkedList2 *list) {
    Node2 *node = list->first;
    while (node != NULL) {
        cout << node->value << ' ';
        node = node->next;
    }
}

void AddAfter(Node2 *node2, Node1 *node1) {
    Node2 *NewNode = new Node2;
    NewNode->value = node1->value;
    NewNode->next = node2->next;
    NewNode->prev = node2;
    node2->next = NewNode;
}

void AddToBegin(Node1 *node1, LinkedList2 *list2) {
    Node2 *NewNode2 = new Node2;
    NewNode2->value = node1->value;
    NewNode2->next = list2->first;
    list2->first = NewNode2;
    list2->first->next->prev = list2->first;
}

void AddElements(LinkedList2 *list2, LinkedList1 *list1) {
    Node1 *node1 = list1->first;
    Node2 *node2;
    while (node1 != NULL) {
        node2 = list2->first;
        do {
            if (node1->value <= list2->first->value) {
                AddToBegin(node1, list2);
                node2 = NULL;

            }
            else if (node1->value >= list2->last->value) {
                AddToEndNode2(list2, node1->value);

                node2 = NULL;
            }
            else if (node1->value >= node2->value && node1->value < node2->next->value) {
                AddAfter(node2, node1);

                node2 = NULL;
            }
            else {
                node2 = node2->next;
            }
        } while (node2 != NULL);
        node1 = node1->next;
    }
}

int main() {
    cout << "Enter elements of list, that you want to add:" << endl;
    LinkedList1 *list1 = ReadList1();

    cout << "Enter elements of sorted list:" << endl;
    LinkedList2 *list2 = ReadList1();

    AddElements(list2, list1);

    cout << "Elemets of sorted array:" << endl;
    PrintList2(list2);

    return 0;
}
