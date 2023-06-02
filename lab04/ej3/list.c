#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"


struct _list {
    list_elem elem;
    list next;    
};

//constructors

list empty(void){
    list new = NULL;

    return new;
}


list addl(list l, list_elem e){
    list new = malloc(sizeof(list_elem));
    new->elem = e;
    new->next = l;

    return new;
}



//operations

bool is_empty(list l){
    return (l==NULL); 
}


list_elem head(list l){
    assert(!is_empty(l));
    list_elem x;
    x = l->elem;

    return x;
}


list tail (list l){
    assert(!is_empty(l));
    list aux;
    aux  = l;
    l=l->next;
    free(aux);
    
    return l;
}

void destroy_list (list l){
    while (l!=NULL)
    {
        l = tail(l);
    }
}

list addr (list l, list_elem e){
    list aux = l;
    list new = malloc(sizeof(list));
    new->elem = e;
    new->next = NULL;

    if (aux != NULL)
    {
        while (aux->next!=NULL)
        {
            aux = aux->next;
        }
        aux->next = new;
    } else {
        l = new;
    }
    
    

    return l;
}

unsigned int length (list l){
    list aux = l;
    unsigned int count = 0;
    while (aux != NULL)
    {   
        aux = aux->next;
        count++;
    }
    
    return count;
}

list concat (list l, list l0){
    list aux = NULL;
    aux = l;
    while (aux!=NULL)
    {
        aux = aux->next;
    }
    aux = l0;

    return l;
}

list_elem index (list l, unsigned int n){
    assert(length(l) > n);
    list aux = NULL;
    aux = l;
    for (size_t i = 1; i < n; i++)
    {
        aux = aux->next;
    }
    
    return aux->elem;
}

list take (list l, unsigned int n){
    unsigned int count = n;
    list aux = NULL;
    aux = l;   
    while (count != 0)
    {
        aux = aux->next;
        count=count-1;
    }
    destroy_list(aux);

    return l;
}

list drop (list l, unsigned int n){
    unsigned int count = n;
    list aux = NULL;  
    while (count != 0)
    {
        aux = l;
        l = l->next;
        aux = NULL;
        free(aux);
        count = count-1;
    }
    
    return l;
}

list copy_list (list l){
    list copy = empty();
    list aux = l;
    while (aux != NULL)
    {
        copy = addr(copy, aux->elem);
        aux = aux->next;
    }
    
    return copy;
}