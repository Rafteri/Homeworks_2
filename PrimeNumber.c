//
// Created by Rafteri on 12.02.2016.
//

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int x){
    int i;
    for (i = 2; i * i < x; i++){
        if ( x%i == 0){
            return false;
        }
    }

    return true;
}

int main() {
    int a;

    scanf("%d", &a);

    if (isPrime(a)){
        printf("It's prime.");
    }
    else {
        printf("It isn't prime.");
    }

    return 0;
};
