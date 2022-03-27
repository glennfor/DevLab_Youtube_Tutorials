#include <stdio.h>
#include<stdlib.h>

int main(){
    printf("\n\t\t===================================\n");
    printf("\tPassword Generator: Generate a strong password\n");
    printf("\n\t\t===================================\n");

    int len;

    printf("\tEnter the length of the password: ");
    scanf("%d",&len);

    char password[len+1];

    int i;
    for(i = 0; i < len; i++){
        password[i] = 33 + rand()%(127 - 33); // 0 and 2^32-1
    }
    password[len] = '\0';

    printf("\tThe password generated is: %s", password);
}