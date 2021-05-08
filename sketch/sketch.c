#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

list* make_list(int val, list* lst){
    list* new_list = (list*)malloc(sizeof(list*));
    if (new_list == NULL){
        fprintf(stderr, "error new list");
        exit(1);
    }
    new_list->val = val;
    new_list->ptr = lst;
    return new_list;
}

int sum_list(list* lst){
    int sum = 0;
    if (lst == NULL){
        return 0;
    }
    
    return lst->val + sum_list(lst->ptr);
}

int main () {
    list* one = make_list(10, make_list(20, make_list(30, NULL)));
    list a3 = {30, NULL};
    list a2 = {20, &a3};
    list a1 = {10, &a2};
    printf("%d\n", a1.ptr->ptr->val);
    printf("%d\n", sum_list(&a1));
    printf("%d\n", sum_list(one));
    return 0;
}