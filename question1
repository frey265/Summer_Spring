#include <stdlib.h>
#include <stdio.h>

int Remove_even (int Array[], int N)
{
    int i,j=0;
    
    //search for even numbers
    for(i=0; i<N; i++){
        if(Array[i]%2!=0){
                Array[j]=Array[i];
                j++;
        }
    }
    return j;
}

int main ()
{
    int N,i;
    //determine size of array
    printf("How many numbers you want to enter?\n");
    scanf("%d",&N);
    
    //allocate space for the N sized array
    int* Array = malloc(N*sizeof(int));
    
    //take thee input from user
    printf("Enter Numbers here\n");
    for(i=0; i<N; i++){
        scanf("%d",&Array[i]);
    }
    
    //show the captured input
    for(i=0; i<N; i++){
        printf("%d ",Array[i]);
    }printf("\n");
    //remove even numbers
    int j = Remove_even(Array,N);
    
    //reallocate memory for array to size j
    int* tmp = realloc(Array, j * sizeof(int));
    
    //print out the outpu
    if(tmp!=NULL){
        Array = tmp;
    }
    for(i=0; i<j; i++){
        printf("%d ",Array[i]);
    }printf("\n");
    free(Array);
    return 0;
}
