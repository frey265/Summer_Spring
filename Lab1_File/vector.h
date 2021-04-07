#ifndef VECTOR_H
#define VECTOR_H //header guard---makes sure that

#define VECTOR_INIT_CAPACITY 1
typedef struct vector{
    void* data;
    int size;
    int capacity;
    int type;
}vector;
void vec_init(vector*,int);
int vec_getsize(vector*);
vector* vec_create(vector*,int);
void vec_grow(vector*);
void vec_get(vector*,int);
void vec_push_int(vector*,int);
void vec_push_flt(vector*,float);
void vec_push_char(vector*,char);
//void vec_gettype(vector*);
void vec_print(vector*);
void vec_pop();
void vec_delete_at(vector*,int);
void vec_swap(vector*,int,int);
int vec_comp(vector*,int,int);
void vec_concate(vector*,vector*);
void vec_map();
void vec_where();
void vec_selection(vector*,int(*vec_comp)(vector*,int,int),void(*vec_swap)(vector*,int,int));
void vec_bubble(vector*,int(*vec_comp)(vector*,int,int),void(*vec_swap)(vector*,int,int));
void vec_sort(vector*);
void vec_conc(vector*);
void vec_menu3(vector*);
#endif