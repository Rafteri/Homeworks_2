//
// Created by Rafteri on 12.04.2016.
//
#include <iostream>
#include <unistd.h>
#include "Tree_5.h"
#include <thread>

using namespace std;

void deleteTree(Node *&root){
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
    }
    delete(root);
}

int count = 0;

void Generate(int num) {
    int size = 250000000, cont = 0;
    Tree *tree;
    for (int i = 0; i  < size; i++) {
        Create(tree);
        Read(tree);
        if (CheckTree(tree)) {
//            cout << "It's binary search tree";
            cont++;
        } else {
//            cout << "It isn't binary search tree";
        }
        if (i % 1000000 == 0) {
            cout << "$$$ " << num << " $$$   ****** " << i/1000000 << " ******" << endl;
        }
        deleteTree(tree->root);
        delete(tree);
    }
    count += cont;
}


int main() {
    int count, size = 1000000000;
//    thread thread1(Generate, 1);
//    thread thread2(Generate, 2);
    thread thread3(Generate, 3);
    thread thread4(Generate, 4);
//    thread1.detach();
//    thread2.detach();
    thread3.detach();
    thread4.join();
//    Tree *tree;
//    for (int i = 0; i  < size; i++) {
//        Create(tree);
//        Read(tree);
//        if (CheckTree(tree)) {
////            cout << "It's binary search tree";
//            count++;
//        } else {
////            cout << "It isn't binary search tree";
//        }
//        if (i % 1000000 == 0) {
//            cout << "****** " << i/1000000 << " ******" << endl;
//        }
//        deleteTree(tree->root);
//        delete(tree);
//    }
    cout << 100.0/size * count << "%";
    return 0;
}
