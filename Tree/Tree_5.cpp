//
// Created by Rafteri on 12.04.2016.
//

#include "Tree_5.h"
#include <iostream>

using namespace std;
void Create(Tree *&tree) {
    tree = new Tree;
    tree->root = nullptr;
}

Node *InsertNode(Node *root, double value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (rand() % 2 < 1) {
        root->left = InsertNode(root->left, value);
    }
    else {
        root->right = InsertNode(root->right, value);
    }
    return root;
}

void Insert(Tree *tree, double value) {
    tree->root = InsertNode(tree->root, value);
}

void Read(Tree *tree) {
    for (int i = 0; i < 5; i++) {
        Insert(tree, i + 1);
    }
//    double value;
//    while (cin.peek() != '\n') {
//        cin >> value;
//        Insert(tree, value);
//    }
//    cin.get();
}

bool IsBinary(Node *root) {
    if (root->left != nullptr) {
        if (root->left->value <= root->value) {
            return IsBinary(root->left);
        } else {
            return false;
        }
    } else if (root->right != nullptr) {
        if (root->right->value > root->value) {
            return IsBinary(root->right);
        } else {
            return false;
        }
    } else {
        return true;
    }

}

bool CheckTree(Tree *tree) {
//    srand(Time(0));
    return IsBinary(tree->root);
}

void InOrder(Node *root)
{
    if (root != nullptr)
    {
        InOrder(root -> left);
        cout << root -> value << " ";
        InOrder(root ->right);
    }
}

void InOrderPrint(Tree *tree)
{
    InOrder(tree->root);
}