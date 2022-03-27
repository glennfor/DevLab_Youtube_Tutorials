#include <stdio.h>

int main(){
	int number;
	printf("Enter a number:\n");
	scanf("%d", &number);
	
	int prime = 1, i ;
	for(i=2; i < number/2; i++){
		if(number%i==0){
			prime = 0;
			break;
		}
	}
	
	if(prime){
		printf("%d is Prime.", number);
	}
	else{
		printf("%d is not prime", number);
	}
}
