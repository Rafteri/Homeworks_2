//
// Created by Rafteri on 9.02.2016.
//

#include <stdio.h>

/**
 * Helper function. Reading specified number of elements
 * into given array
 */
void read(int *a, int size) {
    for (int i = 0; i < size; i++) {
        scanf(" %d", &a[i]);
    }
}

/**
 * Helper function. Printing specified number elements
 * from given array into console using printf
 */
void print(int *a, int size) {
    for (int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
}

/**
 * Sort function. Using bubble sort (O(n*n)) method to sort
 * specified number elements in given array
 */
void bubble_sort(int *a, int size) {
     for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    /* reading size of array */
    unsigned int size;

    /* creating array with specified size */
    printf("Enter number of elements in array:\n");
    scanf(" %d", &size);
    int a[size];

    /* reading elements into array */
    printf("Enter elements of array:\n");
    read(a, size);

    /* sorgint elements */
    bubble_sort(a, size);

    /* printing elements into console */
    printf("Sorted array:\n");
    print(a, size);

    /* printing 2 endline characters for easement */
    printf("\n\n");
    return 0;
}
