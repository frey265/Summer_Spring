#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct Dynamic_Array{
    void* data;
    int type;
    int size;
    int capacity;
}Dynamic;
void get_type(Dynamic* Array ){
    printf("Select Data Type\n");
    printf("1.Integers\n2.Float\n3.Characters\n");
    scanf("%d",&Array->type);
}
int getsize(Dynamic* Array){
    if(Array->type==1) {
        return sizeof(int);
    }else if(Array->type==2) {
        return sizeof(float);
    }else if(Array->type==3){
        return sizeof(char);
    }
}
Dynamic* create_arr(Dynamic* Array,int capacity){ ///initialises the struct
    Dynamic* result = malloc(sizeof(struct Dynamic_Array));
    result->data= malloc(getsize(Array)*capacity);
    result->capacity = capacity;
    return result;
}
void free_arr(Dynamic* Array){
    free(Array);
}
Dynamic* grow_arr(Dynamic*Array){
    if(Array->capacity == Array->size){
        Array->capacity = (Array->capacity) * 2; //increase the capacity
    }
    switch(Array->type){
        case 1: //reallocating the size for data
            Array->data = realloc(Array->data, sizeof(int) * Array->capacity);
            break;
        case 2:
            Array->data = realloc(Array->data, sizeof(float) * Array->capacity);
            break;
        case 3:
            Array->data = realloc(Array->data, sizeof(char) * Array->capacity);
            break;
        default :
            printf("Invalid data type\n");
            break;
    }
    return Array;
}
void print_arr(Dynamic* Array){
    switch(Array->type){
        case 1:
            for(int i=0; i < Array->size; i++){
                printf("%d ",(int*)Array[i].data);
            }printf("\n");
            break;
        case 2:
            for(int i=0; i < Array->size; i++){
                printf("%f ",(float*)Array[i].data);
            }printf("\n");
            break;
        case 3:
            for(int i=0; i < Array->size; i++){
                printf("%c ",(char*)Array[i].data);
            }printf("\n");
            break;
        default:
            printf("\n Unable to identify data type!\n");
            break;
    }
}
void Concate_array(Dynamic* Array1, Dynamic* Array2){
    int z;
    Dynamic *Con;
    //allocate for concar
    Con = (Dynamic*)malloc(sizeof(Dynamic));
    z = Array1->size+Array2->size;//size of the two  arrays
    create_arr(Con,z);
    Con->size=z;
    Con->type=Array1->type;//or Array2
    for(int i=0;i<Array1->size;i++){
        Con[i].data=(void*)Array1[i].data;
    }
    for(int i=Array1->size;i<z+1;i++){
        Con[i].data=(void*)Array2[i].data;
    }
    print_arr(Con);
}
void Concatenation(Dynamic* Array1,Dynamic* Array2){
    Array1=grow_arr(Array1);
    strcat(Array1->data, Array1->data);
    printf("\nThe joined string:\n");
    print_arr(Array1);
}
void swap_func(Dynamic *Array,int i,int j){
    if(Array->type==1){
        void* temp = ((int*)Array[i].data);///dealing with the struct
        Array[i].data = ((int*)Array[j].data);
        Array[j].data = (void*)temp;
    }else if(Array->type==2){
        void* temp = ((float*)Array[i].data);
        Array[i].data = ((float*)Array[j].data);
        Array[j].data = (void*)temp;
    }else if(Array->type==3){
        void* temp = ((char*)Array[i].data);
        Array[i].data = ((char*)Array[j].data);
        Array[j].data = (void*)temp;
    }else{
        printf("Sort type invalid\n");
    }
}
int comp_func(Dynamic* Array,int i,int j){
    if(Array->type==1){
        if (((int*)Array[i].data)> ((int*)Array[j].data))
            return 1;

        if (((int*)Array[i].data) < ((int*)Array[j].data))
            return -1;

        return 0;
    }else if(Array->type==2){
        if (((float*)Array[i].data) > ((float*)Array[j].data))
            return 1;

        if (((float*)Array[i].data) < ((float*)Array[j].data))
            return -1;

        return 0;
    }else if(Array->type==3){
        if (((float*)Array[i].data) > ((float*)Array[j].data))
            return 1;

        if (((float*)Array[i].data) < ((float*)Array[j].data))
            return -1;

        return 0;
    }else{
        printf("Compare type invalid\n");
    }
}
void Bubble_Sort(Dynamic* Array, int (*comp_func)(Dynamic*, int, int), void (*swap_func)(Dynamic*, int, int)){
    for (int i = 0; i < Array->size; i++){
        for (int j = i; j < Array->size; j++){
            if (comp_func(Array, i, j) > 0) // ">" to sort in ascending order
                swap_func(Array, i, j);
        }

    }
}
void Selection_Sort(Dynamic* Array, int (*comp_func)(Dynamic*, int, int), void (*swap_func)(Dynamic*, int, int)){
    int i, j;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < Array->size-1; i++)
    {
        for (j = i+1; j < Array->size; j++) {
            if (comp_func(Array, i, j) > 0)
                swap_func(Array, i, j);
        }
    }
}
void Enter_Input(Dynamic* Array) {
    int input1;
    int num = Array->size;
    printf("->How You Want to enter Data?\n"); //determine the method of input
    printf("1. Random Generation\n2. Console Input\n");
    scanf("%d", &input1); //switch the input type
    switch(Array->type) {
        case 1:
            ///integer type
            switch (input1) {
                case 1: /// random input
                    printf("Random Integer Input Generation\n");
                    srand(time(0));
                    for (int i = 0; i < Array->size; i++) {
                        Array[i].data = (void *) (rand() % 100);
                    }
                    print_arr(Array);//display the input
                    break;
                case 2:///console input
                    printf("Console Integer Input\n");
                    printf("Enter %d numbers\n", num);
                    for (int i = 0; i < num; i++) {
                        scanf("%d", &Array[i].data);
                    }
                    printf("Your Input\n");
                    print_arr(Array);
                    break;
                default:
                    printf("Choice Invalid try Again!\n");
                    Enter_Input(Array);
                    break;
            }
            break;
        case 2:
            //float type
            switch (input1) {
                case 1:///random generation
                    printf("Random Float Input Generation\n");
                    srand(time(0));
                    for (int i = 0; i < num; i++) {
                        *(float *) Array[i].data = ((float) rand() / RAND_MAX) *
                                                   (float) (100.0); //divide random number by a float to get float
                    }
                    print_arr(Array);
                    break;
                case 2:///console input
                    printf("Console Float Input\n");
                    printf("Enter %d decimal numbers\n", num);
                    for (int i = 0; i < num; i++) {
                        scanf("%f", &Array[i].data);
                    }
                    printf("Your Input\n");
                    print_arr(Array);
                    break;
                default:
                    printf("Choice Invalid Sorry Try Again!\n");
                    Enter_Input(Array);
                    break;
            }
            break;
        case 3:
            //character input
            switch(input1) {
                case 1:
                    printf("Random Character Input Generation\n");
                    srand(time(0));
                    for (int i = 0; i < num; i++) {
                        Array[i].data = (void *) (rand() % ((90 - 65)) + 65);//to get capital characters from A to Z
                    }
                    print_arr(Array);
                    break;
                case 2:
                    printf("Console Input\n");
                    printf("Enter %d characters\n", num);
                    for (int i = 0; i < num; i++) {
                        scanf("%c", &Array[i].data);
                    }
                    printf("Your Input\n");
                    print_arr(Array);
                    break;
                default:
                    printf("Choice Invalid Sorry Try Again!\n");
                    Enter_Input(Array);
                    break;
            }
            break;

        default:
            printf("Invalid Option\n");
            Enter_Input(Array);
            break;
    }
}
void menu2(Dynamic* Array){///sorting menu
    printf("\nSelect Sorting Method\n");
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
            Selection_Sort(Array,comp_func,swap_func);
            print_arr(Array);
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
            Bubble_Sort(Array,comp_func, swap_func);
            print_arr(Array);
            end_time = clock();
            total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            printf("\nend_time : %f\n", (float)end_time);//determines the time of sort
            printf("total time of execution = %f\n", total_time);
            break;
        default:
            printf("Sorry Option Invalid, try again\n");
            menu2(Array);
            break;
    }

}
void menu3(Dynamic* Array){///concatenation menu
    Dynamic* Array2;
    int n;
    printf("Enter size of second data\n");
    scanf("%d",&n);///size of the other data part
    Array2 = malloc(sizeof(Dynamic));
    create_arr(Array2,n);
    Array2->type=Array->type;
    Array->capacity=n;
    Array2->size=n;
    Enter_Input(Array2);///get second input
    switch (Array->type) {
        case 1:
            printf("Unfortunately only characters have this option\n");
            break;
        case 2:
            printf("Unfortunately only characters have this option\n");
            break;
        case 3:
            Concatenation(Array,Array2);
            break;
        default:
            printf("Invalid data type\n");
            menu1(Array);
            break;
    }
}
void menu1(Dynamic* Array) {
    int opt;
    printf("\nSelect Option\n");
    printf("1.Sorting\n2.Concatenation\n3.Map\n4.Where\n");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            menu2(Array);//sorting menu
            break;
        case 2:
            menu3(Array);//concatenation menu
            break;
        case 3:
            break; //map
        case 4:
            break;
        default://where
            printf("Option invalid\nTry again\n");
            menu3(Array);
            break;

    }
}
int main() {
    printf("DYNAMIC ARRAY OPERATIONS\n");
    int num;
    printf("Enter data size...\n"); // determine size of data imediately
    scanf("%d", &num);
    Dynamic* Array =malloc(sizeof(Dynamic));
    create_arr(Array,num);
    Array->size = num;//assign size of arra
    get_type(Array);//get the type of the data
    Enter_Input(Array);
    menu1(Array);
    return 0;
}