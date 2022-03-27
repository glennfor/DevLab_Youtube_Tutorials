#include <stdio.h>

int main(){
    printf("\n==================================\n");
    printf("Histogram for data groups:\n");
    printf("==================================\n");

    printf("\nEnter the number of data groups: ");
    int count; 
    scanf("%d", &count);

    int data[count];

    printf("\nEnter the number of items in each group:\n ");

    int i;

    for(i = 0; i < count; i++){
        printf("For Group %d: ", i+1);
        scanf("%d", &data[i]);
    }

    //now generate the histogram

    printf("\n\n");

    int j, k;

    for(i = 0; i < count; i++){
        printf("        \335\n");
        for(j = 1; j <= 3; j++){
            if(j==2)
                printf("Group %-2d\335", i+1);
            else
                printf("        \335");

            for( k = 0; k < data[i]; k++)
                printf("\336");
            
            if(j==2)
                printf("[%d]", data[i]);

            printf("\n");
        }
        
    }
    getch();

}
