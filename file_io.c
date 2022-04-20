#include <stdio.h>

int main(){
    FILE* fp;
    
    char buffer[255];
    fp = fopen(__FILE__, "r");// r, w, a, a+
    while(fgets(buffer, 100, fp)){
        puts(buffer);
    }
}