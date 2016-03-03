//
// Created by Rafteri on 27.02.2016.
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

void ReadList(LinkedList *list) {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        AddToEnd(list, s[i]);
    }
}

void PrintList(LinkedList *list) {
    Node *node = list->first;
    while (node != NULL) {
        cout << node->character;
        node = node->next;
    }
}

void DeleteWord(LinkedList *text, LinkedList *word) {
    Node *Tnode = text->first;
    Node *Wnode = word->first;
    Node *PrevTnode = new Node;
    PrevTnode->character = 0;
    PrevTnode->next = text->first;
    while (Tnode != NULL) {
        if (Tnode->character == Wnode->character) {
            while (Wnode != NULL && Tnode != NULL && Tnode->character == Wnode->character) {
                Tnode = Tnode->next;
                Wnode = Wnode->next;
            }
            if (Wnode == NULL) {
                Wnode = word->first;
                if (Tnode != NULL && Tnode->character == ' ') {
                    Tnode = Tnode->next;
                }
                if (PrevTnode->character == 0) {
                    text->first = Tnode;
                    PrevTnode->next = text->first;
                    PrevTnode->character = 0;
                }
                else {
                    PrevTnode->next = Tnode;
                }
            }
            else {
                while (PrevTnode->next != Tnode) {
                    PrevTnode = PrevTnode->next;
                }
                Wnode = word->first;
            }
        }
        else {
            Tnode = Tnode->next;
            PrevTnode = PrevTnode->next;
        }
    }

}

int main() {
    LinkedList *text = new LinkedList;
    cout << "Enter the text please:" << endl;
    ReadList(text);

    LinkedList *word = new LinkedList;
    cout << "Enter the word please:" << endl;
    ReadList(word);

    DeleteWord(text, word);

    PrintList(text);
    return 0;
};