#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
int main(){
    vector* v1;
    vec_init(v1,1);
    vec_create(v1,6);
    vec_get(v1,10);
    return 0;
}