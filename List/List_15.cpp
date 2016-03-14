//
// Created by Rafteri on 05.03.2016.
//
#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    double r, phi;
    Node *next = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

void AddToEnd (LinkedList *list, double r, double phi) {
    Node *node = new Node;
    node->r = r;
    node->phi = phi;
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
    cout << "Enter  elements(r and phi, through the gap) list" << endl;
    double r, phi;
    while (cin.peek() != '\n') {
        cin >> r;
        if (cin.peek() != '\n') {
            cin >> phi;
            AddToEnd(list, r, phi);
        }
    }
    cin.get();
    return list;
}

void ReadCoeff(double &k, double &x, double &b) {
    cout << "y=k*x + b" << endl;
    cout << "Enter k: " << endl;
    cin >> k;
    cout << "Enter x: " << endl;
    cin >> x;
    cout << "Enter b: " << endl;
    cin >> b;
}

bool CheckCoord(LinkedList *list, double k, double x, double b){
    Node *node = list->first;
    if (node != NULL) {
        while (node != NULL) {
            if (k*x + b == node->r * sin(node->phi)){
                node = node->next;
            }
            else {
                return false;
            }
        }
        return true;
    }
    else {
        cout << "List is emty!";
        return false;
    }
}

int main() {
    LinkedList *list = ReadList();

    double k, x, b;
    ReadCoeff(k, x, b);

    if (CheckCoord(list, k, x, b)) {
        cout << "Coordinates lie on a given line.";
    }
    else {
        cout << "Coordinates don't lie on a given line.";
    }

    return 0;
}