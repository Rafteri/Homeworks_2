//
// Created by Rafteri on 22.02.2016.
//

#include <iostream>
using namespace std;

struct Rational {
    int a, b;
    Rational *next = NULL;
};
struct LinkedList {
    Rational *first = NULL;
    void PrintList(){
        Rational *rational = first;
        while (rational != NULL){
            cout << rational->a << '/' << rational->b << endl;
            rational = rational->next;
        }
    }
};


LinkedList *Farey(int n){
    LinkedList *Farrey = new LinkedList;

    Rational *rational1 = new Rational;
    rational1->a = 0;
    rational1->b = 1;
    Farrey->first = rational1;

    Rational *rational2 = new Rational;
    rational2->a = 1;
    rational2->b = 1;
    Farrey->first->next = rational2;

    for (int i = 0; i < n + 1; i++) {
        rational1 = Farrey->first;
        rational2 = Farrey->first->next;
        while (rational2 != NULL) {
            if ((rational1-> b + rational2->b) == i) {
                Rational *rational = new Rational;
                rational->a = rational1->a + rational2->a;
                rational->b = rational1->b + rational2->b;

                rational1->next = rational;
                rational->next = rational2;
                rational1 = rational2;
                rational2 = rational2->next;          }
            else{
                rational1 = rational1->next;
                rational2 = rational2->next;
            }
        }
    }
    return Farrey;
}

int main() {
    int n;
    cin >> n;
    LinkedList *Farrey = Farey(n);
    Farrey->PrintList();
    return 0;
}