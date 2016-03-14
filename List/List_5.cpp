//
// Created by Rafteri on 01.03.2016.
//
#include <iostream>
using namespace std;

struct Node {
    char character;
    Node *next = NULL;
};

struct LinkedList {
    Node *first = NULL;
    Node *last = NULL;
};

void AddToEnd(LinkedList *list, char c) {
    Node *node = new Node;
    node->character = c;
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

LinkedList *ReadList() {
    LinkedList *list = new LinkedList;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        AddToEnd(list, s[i]);
    }
    return list;
}

bool IncludeVerify(LinkedList *text, LinkedList *Word) {
    Node *Tnode = text->first;
    Node *Wnode = Word->first;

    while (Tnode != NULL) {
        if (Tnode->character == Wnode->character) {
            while (Wnode != NULL && Tnode != NULL && Tnode->character == Wnode->character) {
                Tnode = Tnode->next;
                Wnode = Wnode->next;
            }
            if (Wnode == NULL) {
                return true;
            }
            Wnode = Word->first;
        }
        else {
            Tnode = Tnode->next;
        }
    }
    return false;
}

int main() {
    cout << "Enter the text please:" << endl;
    LinkedList *text = ReadList();

    cout << "Enter word:" << endl;
    LinkedList *Word = ReadList();

    if (IncludeVerify(text, Word)) {
        cout << "The word is  included in the text.";
    }
    else {
        cout << "The word isn't  included in the text.";
    }
    return 0;
}
