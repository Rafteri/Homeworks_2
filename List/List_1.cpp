//
// Created by Rafteri on 21.02.2016.
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

bool IsChar(char c) {
    return (((c >= 64) && (c < 91)) || ((c > 96) && (c < 123)));
}

LinkedList *FoundMaxWord(LinkedList *text, int *curlength) {
    LinkedList *MaxWord = new LinkedList;
    int length = 0;
    Node *node = text->first;
    Node *wnode; //word node
    Node *CurWord; // current word

    while (node != NULL) {
        if (IsChar(node->character)) {
            CurWord = node;
            while (node != NULL && IsChar(node->character)) {
                length++;
                node = node->next;
            }
            if (length > *curlength) {

                *curlength = length;
                wnode = MaxWord->first;
                do {
                    if (wnode == NULL) {
                        AddToEnd(MaxWord, CurWord->character);
                        CurWord = CurWord->next;
                    }
                    else {
                        wnode->character = CurWord->character;
                        CurWord = CurWord->next;
                        wnode = wnode->next;
                    }
                } while (CurWord != node);
            }
            length = 0;
        }
        else {
            node = node->next;
        }
    }
    return MaxWord;
}

int main() {
    LinkedList *text = new LinkedList;
    ReadList(text);
    int length = 0;

    LinkedList *MaxWord = FoundMaxWord(text, &length);

    PrintList(MaxWord);
    cout << endl << "Length of MaxWord: " << length;

    return 0;
}



