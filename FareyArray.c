//
// Created by Rafteri on 16.02.2016.
//

#include <stdio.h>

struct Rational {
    int a, b;
};

void Farey(int n){

    const int size = 10000;
    struct Rational num[size];
    int i, k = 2;

    num[0].a = 0;
    num[0].b = 1;

    num[1].a = 1;
    num[1].b = 1;
    for (i = 0; i < n + 1; i++) {
        int j = 0;
        while (j < k - 1) {
            if ((num[j].b + num[j + 1].b) == i) {
                int l;
                for (l = k + 1; l > j + 1; l--) {
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

    for (i = 0;  i < k ; i++){
            printf("%d/%d \n", num[i].a, num[i].b);
        }
}

int main() {
    int n;
    scanf("%d", &n);
    Farey(n);
    return 0;
}
