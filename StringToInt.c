//
// Created by Rafteri on 15.02.2016.
//
#include <stdio.h>
#include <stdbool.h>


int TryParse(char num[], bool *success){
    int i, number = 0;
    for (i = 0; num[i]; i++){
        if ((num[i] >= '0') && (num[i] <= '9')){
            number = number * 10 + num[i] - '0';
        }
        else {
            *success = false;
            return -1;
        }
    }
    *success = true;
    return number;
}

int main() {
    bool succes;
    int number;
    char num[20];
    scanf("%s", num);

    number = TryParse(num, &succes);

    if (succes) {
        printf("Your number: %d", number);
    }
    else {
        printf("You haven't entered the number!");
    }
    return 0;
}
