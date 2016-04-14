//
// Created by Rafteri on 12.04.2016.
//

#ifndef TREE_TREE_5_H
#define TREE_TREE_5_H

struct Node {
    double value;
    Node *right = nullptr;
    Node *left = nullptr;
};

struct Tree {
    Node *root;
};
void Read(Tree *tree);
void Create(Tree *&tree);
bool CheckTree(Tree *tree);
void InOrderPrint(Tree *tree);
#endif //TREE_TREE_5_H
