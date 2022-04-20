//We will be implementing the fibonacci series in 3 different ways
//-Recursion
//-Memoization (ie an array is used to store previously calculated values)
//-Iteration

//Typically fib(n) = fib(n-1) + fib(n-2)

//implementation will take an interger n and return nth fibonacci number
// fibonacci number quickly grow large so we will use long int

//Also implementation fibonacci series slights varies with some version satrting with {0,1} and others {1,1}
//Ours starts with 0,1

#include <stdio.h>

//define function protypes

long fibonacciRecursion(int n); //recursive function

long fibonacciArray(int n); // memoization function

long fibonacciIteration(int n); //iteration function


//test

int main(){
    //perform some testing to see how well it works
    int position;
    printf("Enter a position in fibonaci series: ");
    scanf("%i", &position); //yeah, you can use %i instead of %d for integres

    printf("fibonacci Series Number at position %d:\n", position);
    printf("Function      Value\n"); //check the values produced by each function
    printf("=============================\n");
    printf("Iteration  :  %ld\n", fibonacciIteration(position));
    printf("Memoization:  %ld\n", fibonacciArray(position));
    printf("Recursion  :  %ld\n", fibonacciRecursion(position));
}

//implementation of all functions

//recursion
long fibonacciRecursion(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return fibonacciRecursion(n-1) + fibonacciRecursion(n-2);
    }
}//easy-pizzy

//memoization

long fibonacciArray(int n){
    long memo[n];
    memo[0] = 0;
    memo[1] = 1;
    int i  = 2;
    while(i < n){
        memo[i] = memo[i-1] + memo[i-2];
        i++;
    }
    return memo[n-1]; //array indexing starts from 0 so n-1 is for nth term
}

//iteration
long fibonacciIteration(int n){
    long termOne = 0, termTwo = 1;
    int i = 1; //first two terms counted already
    while(i < n){
        long temp = termTwo;
        termTwo = termOne + termTwo;
        termOne = temp;
        i++;
    }
    return termOne;
}

//works perfectly