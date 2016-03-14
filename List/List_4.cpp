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

void Replace(Node *Tnode, Node *CurTnode, LinkedList *AddWord) {
    CurTnode->character = AddWord->first->character;
    CurTnode->next = AddWord->first->next;
    AddWord->last->next = Tnode;
}

void AddingWord(LinkedList *text, LinkedList *PrevWord, LinkedList *AddWord) {
    Node *Tnode = text->first;
    Node *Wnode = PrevWord->first;
    Node *CurTnode;

    while (Tnode != NULL) {
        if (Tnode->character == Wnode->character) {
            CurTnode = Tnode;
            while (Wnode != NULL && Tnode != NULL && Tnode->character == Wnode->character) {
                Tnode = Tnode->next;
                Wnode = Wnode->next;
            }
            if (Wnode == NULL) {
                Replace(Tnode, CurTnode, AddWord);
                Tnode = NULL;
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

    cout << "Enter word, that you want to replace:" << endl;
    LinkedList *PrevWord = ReadList();

    cout << "Enter the word, that you want to add:" << endl;
    LinkedList *AddWord = ReadList();

    AddingWord(text, PrevWord, AddWord);

    PrintList(text);
    return 0;
}
