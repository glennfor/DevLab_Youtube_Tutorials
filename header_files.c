//Program to reverse a number
//eg  1234 to 4321

#include <stdio.h>

int main(){
    int number, reversed;

    printf("Enter a number to reverse: ");
    scanf("%d", &number);
    reversed = 0;
    while(number){
        reversed = reversed * 10 + number%10;
        number /= 10;
    }
    printf("The reversed number is: %d", reversed);
}

