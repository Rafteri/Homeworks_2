//
// Created by Rafteri on 9.02.2016.
//

#include <stdio.h>

int main() {
    const int size = 10;
    int a[size];

    int i;

    printf("Enter elements of array: \n");
    for (i = 0; i < size; i++) {
        scanf(" %d", &a[i]);
    }

    int j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++){
            if (a[j] > a[j + 1]){
                a[j] = a[j] + a[j + 1];
                a[j + 1] = a[j] - a[j + 1];
                a[j] = a[j] - a[j + 1];
            }
        }
    }

    printf("Sorted array:");
    for (i = 0; i < size; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
