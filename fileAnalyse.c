//program to analyse any text file 

// in this program we will analyse the source code itself! cool!!!

#include <stdio.h>
#include <ctype.h>

//ctype.h has functions defined as macros for manipulations
//and checks on characters

//upcoming video on header files will cover that

typedef enum{FALSE, TRUE} Bool;
//C does not have native boolean type so we create ours


int main(){

    int lineCount, wordCount, charCount;
    lineCount = wordCount = charCount = 0;

    // you can get the name of the file containing the source
    //code by using the __FILE__ macro which is natively defined

    //create a file pointer for reading
    FILE* fp = fopen(__FILE__, "r");

    int ch = fgetc(fp);

    //to count words we have to note all spaces and increase count by
    //1 when a stream of letters is encountered

    Bool isSpace = FALSE; //initialy assume we are starting with a letter

    while(ch != EOF){
        charCount ++;

        if (ch == '\n') lineCount ++;

        if(isspace(ch)){
            isSpace = TRUE;
        }
        else if(isSpace){
            isSpace = FALSE;
            wordCount++;
        }
        //get the next letter
        ch = fgetc(fp);

    }

    //now print all the results

    printf("Results of anlysing the file\n");
    printf("=======================================\n");
    printf("Number of Lines:   %d\n", lineCount);
    printf("Number of Words:   %d\n", wordCount);
    printf("Number of Chars:   %d\n", charCount);
    printf("=======================================\n");
}

//now test

//note the number of lines in this file to compare

//note the lines are 1 less because the last line does not have a 
//new line character. 


//join the telegram channel to get the source code.
//Join telegram group for discussing any issues

//HAPPY CODING!!!!!