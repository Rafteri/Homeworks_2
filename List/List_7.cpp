//
// Created by Rafteri on 01.03.2016.
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


void AddValue(LinkedList *text, double y, double x) {

    if (text->first->value = y) {
        Node *node = new Node;
        node->value = x;
        node->next = text->first;
        text->first = node;
    }

    Node *node = text->first->next;
    while (node->next != NULL) {
        if (node->next->value == y) {
            Node *Newnode = new Node;
            Newnode->value = x;
            Newnode->next = node->next;
            node->next = Newnode;
            node = node->next->next;
        }
        else {
            node = node->next;
        }
    }

}

int main() {
    LinkedList *text = new LinkedList;
    cout << "Enter the text please:" << endl;
    ReadList(text);

    double y;
    cout << "Enter the value before which you want to add the value:";
    cin >> y;

    double x;
    cout << "Enter the value, that you want to add:";
    cin >> x;

    AddValue(text, y, x);

    PrintList(text);
    return 0;
}