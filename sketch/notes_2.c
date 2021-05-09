#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// error segmentation! malloc sizeof (intlist*)

// stack allocated array can't shrink.
// heap allocated might ... with realloc 
    // [1,2,3] ... , yes
    // [1,2,3] [4], need copy to other place

// Linked lists


intlist* make_list(int val, intlist* lst){
    intlist* new_list = (intlist*)malloc(sizeof(intlist));
    if (new_list == NULL){
        fprintf(stderr, "error new list");
        exit(1);
    }
    new_list->val = val;
    new_list->next = lst;
    return new_list;
}

int sum_list(intlist* lst){
    int sum = 0;
    if (lst == NULL){
        return 0;
    }
    
    return lst->val + sum_list(lst->next);
}


// free linked list
void free_list(intlist* list){
    intlist* next;
    while(list){
        next = list->next;
        free(list);
        list = next;
    }
    printf("list freed \n");
}

// todo: 1-D and 2-D array free

//

intlist* remove_front(intlist* lst){
    intlist* temp = lst;
    free(lst);
    return temp->next;
}

// intlist* list1 = make(...)
// update_front(&list1)
void update_front(intlist** lst){
    intlist* temp = *lst;
    *lst = temp->next;
    // *lst = *lst->next;
    free(temp);    
}

intlist* find_evens(intlist* lst){
    intlist* curr = lst;
    intlist* head = NULL;
    intlist* tail;
    while(curr){
        if(curr->val % 2 == 0) {
            intlist* item = make_list(curr->val, NULL);
            if(head == NULL){
                head = item;
            } else {
                tail->next = item;
            }
            tail = item;
        }
        curr = curr->next;
    }
    return head;
}
