//
// Created by Rafteri on 12.02.2016.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * Prime number determination function.
 * Using eratosphene sieve.
 */
bool is_prime(int x) {
    /* calculating square root from x */
    int size = (int)(sqrt(x));
    /* allocating bool array with size length */
    bool dividers[size + 1];
    for (int i = 0; i <= size; ++i) {
        dividers[i] = true;
    }
    
    /** loop in range [2, size]
     * dividers array used to exclude divider's dividers
     * for example: if 2 isn't divider of x,
     * then exclude all miltiples of 2 in range [2, size]
     */
    for (int i = 2; i <= size; ++i) {
        if (dividers[i] && x%i == 0) {
            return false;
        } else {
            for (int j = i; j <= size; j+=i)
            {
                dividers[j] = false;
            }
        }
    }
    /* if we din't found dividers - number is prime */
    return true;
}

int main() {
    /* read number */
    int a;
    printf("Enter number to check if it's prime:\n");
    scanf("%d", &a);

    /* check if it's prime and print the result */
    if (is_prime(a)){
        printf("It's prime.");
    } else {
        printf("It isn't prime.");
    }

    /* print two endline characters for easement */
    printf("\n\n");
    return 0;
};
