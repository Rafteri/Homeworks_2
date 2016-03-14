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

void PrintList(LinkedList *list) {
    Node *node = list->first;
    while (node != NULL) {
        cout << node->character;
        node = node->next;
    }
}

bool IsChar(char c) {
    return (((c >= 64) && (c < 91)) || ((c > 96) && (c < 123)));
}

void AddAfter(Node *Tnode, Node *Curnode, LinkedList *AddWord) {

    Node *end = Tnode;

    if (Tnode == NULL || !IsChar(Tnode->character)) {
        Node *gap = new Node;
        gap->character = ' ';
        gap->next = Tnode;
        Curnode->next = gap;
        Curnode = Curnode->next;
    }

    Node *Addnode = AddWord->first;
    while (Addnode != NULL) {
        Node *NewChar = new Node;
        *NewChar = *Addnode;
        Curnode->next = NewChar;
        Curnode = Curnode->next;
        Addnode = Addnode->next;
    }

    Curnode->next = end;
}

void AddingWord(LinkedList *text, LinkedList *PrevWord, LinkedList *AddWord) {
    Node *Tnode = text->first;
    Node *Wnode = PrevWord->first;
    Node *Curnode;

    while (Tnode != NULL) {
        if (Tnode->character == Wnode->character) {
            while (Wnode != NULL && Tnode != NULL && Tnode->character == Wnode->character) {
                Curnode = Tnode;
                Tnode = Tnode->next;
                Wnode = Wnode->next;
            }
            if (Wnode == NULL) {
                AddAfter(Tnode, Curnode, AddWord);
            }
            Wnode = PrevWord->first;
        }
        else {
            Tnode = Tnode->next;
        }
    }

}

int main() {
    cout << "Enter the text please:" << endl;
    LinkedList *text = ReadList();

    cout << "Enter previous word:" << endl;
    LinkedList *PrevWord = ReadList();

    cout << "Enter the word, that you want to add:" << endl;
    LinkedList *AddWord = ReadList();

    AddingWord(text, PrevWord, AddWord);

    PrintList(text);
    return 0;
}
