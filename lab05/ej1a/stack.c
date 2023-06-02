#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    stack next;
};


stack stack_empty() {
    stack new = NULL;

    return new;
}

stack stack_push(stack s, stack_elem e) {
    stack new = malloc(sizeof(stack));
    new->elem = e;
    new->next = s;

    return new;
}

stack stack_pop(stack s) {
    stack aux = s->next;
    free(s);

    return aux;
}

unsigned int stack_size(stack s) {
    stack aux = s;
    unsigned int count = 0;
    while (aux!=NULL)
    {
        aux = aux->next;
        count++;
    }
    
    return count;
}

stack_elem stack_top(stack s) {
    return s->elem;
}

bool stack_is_empty(stack s) {
    return (s==NULL);
}

stack_elem *stack_to_array(stack s) {
    stack_elem *a;
    unsigned int n = stack_size(s);
    stack aux = s;

    a = calloc(n, sizeof(stack_elem));
    
    if(n==0){
        a=NULL;
    } else {
        while (n!=0)
        {
            a[n] = aux->elem;
            aux=aux->next;        
            n = n-1;
        }
    }
    
    return a;
}

stack stack_destroy(stack s) {
    stack aux = s;
    
    while (s!=NULL)
    {
        s=s->next;
        aux->next = NULL;
        free(aux);
        aux = s;
    }
    
    return s;
}