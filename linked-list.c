//Program implementation of a linked list for student data in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//define the structure to hold the data
struct Record{
    char name[32];//student name
    char matricule[10];//matricule
    double gpa; //gpa
    struct Record *next; //pointer to the next record in the list
};

typedef struct Record Student; //I wont have to write this every time

//Now declare the head of the list and initialise

Student* head = NULL; //no student yet


//create a function that creates a student record from data and returns a pointer

Student* createStudent(char name[], char matricule[], double gpa){
    //allocating enough memory to hold student data
    Student* newStudent = (Student*)malloc(sizeof(Student)); 
    //now populate the student record with the data passed
    newStudent->gpa = gpa;
    //strings need to be copied with this function 
    strcpy(newStudent->name, name);
    strcpy(newStudent->matricule, matricule);
    newStudent->next = NULL;
    return newStudent;
}


//This implemetation will only have three main functions
//-create student, insert student record,  and print the linked list items
//A typical implementation of linked list will have more functions for extra functionality
//but this is basic and enough for this use case

//insert a student record into the list
void insert(char name[], char matricule[], double gpa){
    Student* newStudent = createStudent(name, matricule, gpa);
    if(head == NULL){
        head = newStudent;
        return;
    }
    //create a varibale to iterate through the linked list
    Student* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newStudent;
}

//now write a small utility function to print the student data for debugging

void print(){
    // start from the head and iterate till the null pointer is reached and print
    //each record in anyway you want
   Student* tmp = head;

    while(tmp != NULL){
        printf("==========================\n");
        printf("|Name:   %.20s\n", tmp->name);
        printf("|Matricule:   %s\n", tmp->matricule);
        printf("|GPA:   %.2g\n", tmp->gpa);
        printf("===========================\n");
        tmp = tmp -> next;
    } 
}

//now to test the program

int main(){

    //test will be done by entering data for 4 students and printing to make sure everything
    // is working
    int i;
    char name[64], matricule[10]; // for name and matricule
    double gpa;
    printf("Enter some student data for 4 students to test: \n");
    
    for(i = 0; i < 4; i++){
        printf("----------------------------------------\n");
        printf("Enter name: ");
        gets(name); 
        printf("Enter matricule: ");
        gets(matricule);
        printf("Enter gpa: ");
        scanf("%lf", &gpa); 
        //flush is a function that is used to clear our input buffer so that our program can read
        //data from the keyboard correctly

        //experimet=nt removing it to see the effect it causes
        fflush(stdin);
		
        //after collecting the data of each record, it is inserted into the linked list
        insert(name, matricule, gpa);
        
    }

    printf("\n\n\n");
    printf("The data you entered for the students are as below\n\n");

    print();// now print the info for us to see
}


//LEts test the implementation


//Works perfectly