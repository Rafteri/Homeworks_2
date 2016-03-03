//
// Created by Rafteri on 18.02.2016.
//

#include <iostream>
using namespace std;

struct Rational {
    int a, b;
};

void print(Rational num[], int k){
    for (int i = 0;  i < k ; i++){
        cout << num[i].a << '/' << num[i].b << endl;
    }
}

Rational* Farey(int n, int &k){
    const int size = 10000;
    Rational* num = new Rational[size];
    k = 2;

    num[0].a = 0;
    num[0].b = 1;

    num[1].a = 1;
    num[1].b = 1;

    for (int i = 0; i < n + 1; i++) {
        int j = 0;
        while (j < k - 1) {
            if ((num[j].b + num[j + 1].b) == i) {
                for (int l = k + 1; l > j + 1; l--) {
                    num[l] = num[l - 1];
                }
                num[j + 1].a = num[j].a + num[j + 2].a;
                num[j + 1].b = num[j].b + num[j + 2].b;

                j++;
                k++;
            }
            j++;
        }
    }
    return num;
}

int main() {
    int n, k;
    cin >> n;
    Rational* num = Farey(n, k);
    print(num, k);
    return 0;
}
