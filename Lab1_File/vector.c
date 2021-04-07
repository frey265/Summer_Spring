#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "vector.h"

void vec_init(vector* Array,int type){
    Array->size = VECTOR_INIT_CAPACITY;
    Array->capacity = 0;
    Array->type =type;
    Array->data = NULL;
}
int vec_getsize(vector* Array){
    if(Array->type==1) {
        return sizeof(int);
    }else if(Array->type==2) {
        return sizeof(float);
    }else if(Array->type==3){
        return sizeof(char);
    }return 0;
}
vector* vec_create(vector* Array,int size){
    Array->data= malloc(vec_getsize(Array)*size);
    Array->size = size;
    return Array;
}
void vec_print(vector* Array){
    switch(Array->type){
        case 1:
            for(int i=0; i < Array->capacity; i++){
                printf("%d ",((int*)(Array->data))[i]);
            }printf("\n");
            break;
        case 2:
            for(int i=0; i < Array->capacity; i++){
                printf("%.3f ",((float*)(Array->data))[i]);
            }printf("\n");
            break;
        case 3:
            for(int i=0; i < Array->capacity;i++){
                printf("%c ",((char*)(Array->data))[i]);
            }printf("\n");
            break;
        default:
            printf("\n Unable to identify data type!\n");
            break;
    }
}
void vec_grow(vector* Array){
    while (Array->data!=NULL)
    {
        if(Array->size==Array->capacity){
            int new_size = Array->size*2; //inrease size by 2
            void* temp_data = malloc(sizeof(Array->type)*new_size); // store data temp
            memcpy(temp_data,Array->data,Array->size); //copy it to temp
            Array->data = realloc(Array->data,vec_getsize(Array)*new_size); //increase size of data
            memcpy(Array->data,temp_data,Array->size); //copy old data to new sized array
        }
        
    }
  
}
void vec_get(vector* Array,int num){
    printf("SELECT INPUT METHOD\n");
    printf("1. Random Generation\n2. Console Input\n");
    int input1;
    scanf("%d", &input1);
    if(Array->size<num){
        vec_grow(Array);
    }
    switch(Array->type) {
        case 1:
            ///integer type
            switch (input1) {
                case 1: /// random input
                    printf("Random Integer Input Generation\n");
                    srand(time(0));
                    for (int i = 0; i < num; i++) {
                        ((int*)(Array->data))[i]  = (rand()%100);
                        Array->capacity++;
                    }
                    vec_print(Array);//display the input
                    break;
                case 2:///console input
                    printf("Console Integer Input\n");
                    printf("Enter %d numbers\n",  num);
                    for (int i = 0; i <  num; i++) {
                        scanf("%d", &((int*)(Array->data))[i]);
                        Array->capacity++;
                    }
                    printf("Your Input\n");
                    vec_print(Array);
                    break;
                default:
                    printf("Choice Invalid try Again!\n");
                    vec_get(Array,num);
                    break;
            }
            break;
        case 2:
            //float type
            switch (input1) {
                case 1:///random generation
                    printf("Random Float Input Generation\n");
                    srand(time(0));
                    for (int i = 0; i <  num; i++) {
                        ((float*)(Array->data))[i] = ((float) rand() / RAND_MAX) *
                                                   (float) (100.0); //divide random number by a float to get float
                        Array->capacity++;
                    }
                    vec_print(Array);
                    break;
                case 2:///console input
                    printf("Console Float Input\n");
                    printf("Enter %d decimal numbers\n",  num);
                    for (int i = 0; i < num; i++) {
                        scanf("%f", &((float*)(Array->data))[i]);
                        Array->capacity++;
                    }
                    printf("Your Input\n");
                    vec_print(Array);
                    break;
                default:
                    printf("Choice Invalid Sorry Try Again!\n");
                    vec_get(Array,num);
                    break;
            }
            break;
        case 3:
            //character input
            switch(input1) {
                case 1:
                    printf("Random Character Input Generation\n");
                    srand(time(0));
                    for (int i = 0; i <  num; i++) {
                       ((char*)(Array->data))[i] = (rand() % ((90 - 65)) + 65);//to get capital characters from A to Z
                       Array->capacity++;
                    }
                    vec_print(Array);
                    break;
                case 2:
                    printf("Console Input\n");
                    printf("Enter %d characters\n", num);
                    for (int i = 0; i <  num; i++) {
                        scanf("%c", &((char*)(Array->data))[i]);
                        Array->capacity++;
                    }
                    printf("Your Input\n");
                    vec_print(Array);
                    break;
                default:
                    printf("Choice Invalid Sorry Try Again!\n");
                    vec_get(Array,num);
                    break;
            }
            break;

        default:
            printf("Invalid Option\n");
            vec_get(Array,num);
            break;
    }
}
void vec_push_int(vector* Array,int new_data){
    if(Array->size==Array->capacity){
        vec_grow(Array);
    }
    for(int i=0;i<Array->size;i++){
            (((int*)Array->data)[i+1])= (((int*)Array->data)[i+2]);
            }
            (((int*)Array->data)[0]) = new_data;
            Array->capacity++;
}
void vec_push_flt(vector* Array,float new_data){
   if(Array->size==Array->capacity){
        vec_grow(Array);
   }
    for(int i=0;i<Array->size;i++){
                (((float*)Array->data)[i+1])= (((float*)Array->data)[i+2]);
            }
            (((float*)Array->data)[0]) = new_data;
            Array->capacity++;
}
void vec_push_char(vector* Array,char new_data){
    if(Array->size==Array->capacity){
        vec_grow(Array);
    }
    for(int i=0;i<Array->size;i++){
                (((char*)Array->data)[i+1])= (((char*)Array->data)[i+2]);
            }
            (((char*)Array->data)[0]) = new_data;
             Array->capacity++;
}

void vec_pop(){ 
    vector* Array;
    int top;
    top = Array->capacity-1;//get pos of last element
    if(Array->data==NULL){
        printf("The array is empty!\n");
    }
    switch(Array->type){
        case 1:
            printf("Removed %d",((int*)(Array->data))[top]);
            Array->capacity--;
        break;
        case 2:
            printf("Removed %f",((float*)(Array->data))[top]);
            Array->capacity--;
        break;
        case 3:
            printf("Removed %c",((char*)(Array->data))[top]);
            Array->capacity--;
        break;
    }
}
void vec_delete_at(vector* Array,int pos){
    if(Array->data==NULL){
        printf("Array is empty!\n");
    }
    switch(Array->type){
        case 1:
            printf("Removed %d",((int*)(Array->data))[pos]);
            for(int i =pos;i<Array->capacity-2;i++){
                ((int*)(Array->data))[i] = ((int*)(Array->data))[i+1];
            }
            Array->capacity--;
        break;
        case 2:
            printf("Removed %f",((float*)(Array->data))[pos]);
            for(int i =pos;i<Array->capacity-2;i++){
                ((float*)(Array->data))[i] = ((float*)(Array->data))[i+1];
            }
            Array->capacity--;
        break;
        case 3:
            printf("Removed %c",((char*)(Array->data))[pos]);
            for(int i =pos;i<Array->capacity-2;i++){
                ((char*)(Array->data))[i] = ((char*)(Array->data))[i+1];
            }
            Array->capacity--;
        break;
    }

}
void vec_swap(vector* Array,int i,int j){
      if(Array->type==1){
        int temp =  ((int*)(Array->data))[i];  //swaps the interger data type
        ((int*)(Array->data))[i] = ((int*)(Array->data))[j];
         ((int*)(Array->data))[j] = temp;
    }else if(Array->type==2){   //swaps the float data type
         float temp = ((float*)(Array->data))[i];
        ((float*)(Array->data))[i] = ((float*)(Array->data))[j];
        ((float*)(Array->data))[j] = temp;
    }else if(Array->type==3){ //swaps the char data type
        char temp = ((char*)(Array->data))[i];
        ((char*)(Array->data))[i]= ((char*)(Array->data))[j];
        ((char*)(Array->data))[j] = temp;
    }else{
        printf("Sort type invalid\n");
    }
}
int vec_comp(vector* Array,int i,int j){
    if(Array->type==1){
        if (((int*)(Array->data))[i]> ((int*)(Array->data))[j])
            return 1;

        if (((int*)(Array->data))[i] <((int*)(Array->data))[j])
            return -1;

        return 0;
    }else if(Array->type==2){
        if (((float*)(Array->data))[i]> ((float*)(Array->data))[j])
            return 1;

        if (((float*)(Array->data))[i]< ((float*)(Array->data))[j])
            return -1;

        return 0;
    }else if(Array->type==3){
        if (((char*)(Array->data))[i]> ((char*)(Array->data))[j])
            return 1;

        if (((char*)(Array->data))[i]< ((char*)(Array->data))[j])
            return -1;

        return 0;
    }
    return 0;
}
void vec_bubble(vector* Array, int(*vec_comp)(vector*, int, int), void(*vec_swap)(vector*, int, int)){
    for (int i = 0; i < Array->size; i++){
        for (int j = i; j < Array->size; j++){
            if (vec_comp(Array, i, j) > 0) // ">" to sort in ascending order
                vec_swap(Array, i, j);
        }

    }
}
void vec_selection(vector* Array, int (*vec_comp)(vector*, int, int), void (*vec_swap)(vector*, int, int)){
    int i, j;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < Array->size-1; i++)
    {
        for (j = i+1; j < Array->size; j++) {
            if (vec_comp(Array, i, j) > 0)
                vec_swap(Array, i, j);
        }
    }
}


void vec_concate(vector* Array1,vector* Array2){
    if(Array1->data&&Array2->data==NULL){
        printf("Invalid concate get data!\n");
    }
    int n = Array1->size+Array2->size; //get the size of the two arrays combined
    vector* Array3;
    vec_init(Array3,Array1->type);
    vec_create(Array3,n);
    printf("The concate result...\n");
    printf("%d elements\n",n);
    switch (Array3->type){ // types of the three arrays are the same
    case 1: //integer data type
        for(int i=0; i<Array1->size;i++){
             ((int*)(Array3->data))[i]=((int*)(Array1->data))[i];
             ((int*)(Array3->data))[Array1->size+i]=((int*)(Array2->data))[i];
        }
        vec_print(Array3);
        break;
    case 2: //float data type
        for(int i=0; i<Array1->size;i++){
             ((float*)(Array3->data))[i]=((float*)(Array1->data))[i];//copy elements
             ((float*)(Array3->data))[Array1->size+i]=((float*)(Array2->data))[i];//take the other part too at the same time
        }
        vec_print(Array3);
        break;
    case 3: //char data type
         for(int i=0; i<Array1->size;i++){
             ((char*)(Array3->data))[i]=((char*)(Array1->data))[i];
             ((char*)(Array3->data))[Array1->size+i]=((char*)(Array2->data))[i];
        }
        vec_print(Array3);
        break;
    default:
        printf("Concate error!!\n");
        break;
    }
}

void vec_sort(vector* Array){
     printf("\nSELECT SORT METHOD\n");
    printf("1. Selection Sort\n2. Bubble Sort\n");
    int opt;
    clock_t start_time, end_time; // data type for calculating time
    double total_time; // variable for calculating total time
    scanf("%d",&opt);
    switch(opt){
        case 1:
            printf("Selection Sort\n");
            printf("Your Sorted Data:\n");
            // calculating clock when sorting starts..
            printf("start time : %f\n\n", (float)start_time);
            vec_selection(Array,vec_comp,vec_swap);
            vec_print(Array);
            end_time = clock();
            total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            printf("\nend_time : %f\n", (float)end_time);//determines the time of sort
            printf("\ntotal time of execution = %f\n", total_time);
            break;
        case 2:
            printf("Bubble Sort\n");
            printf("The Sorted Data:\n");
            start_time = clock();
            printf("start time : %f\n\n", (float)start_time);
            vec_bubble(Array,vec_comp,vec_swap);
            vec_print(Array);
            end_time = clock();
            total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            printf("\nend_time : %f\n", (float)end_time);//determines the time of sort
            printf("total time of execution = %f\n", total_time);
            break;
        default:
            printf("Sorry Option Invalid, try again\n");
            vec_sort(Array);
            break;
    }
}
void vec_conc(vector* Array){
        int n;
    printf("Enter size of second data\n");
    scanf("%d",&n);
    vector* Array2;
    vec_init(Array2,Array->type);
    vec_create(Array2,n);
    Array2->type=Array->type; //types are the same
    vec_get(Array2,n);///get second input
    vec_concate(Array,Array2);
    free(Array2);
}
