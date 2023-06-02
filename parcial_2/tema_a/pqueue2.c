#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    unsigned int size;
    struct s_node *first;
};

struct s_node {
    pqueue_elem elem;
    unsigned int priority;
    struct s_node *next;
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = malloc(sizeof(struct s_node));
    
    assert(new_node!=NULL);
    
    new_node->elem = e;
    new_node->priority = priority;
    new_node->next = NULL;

    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    
    node->next=NULL;
    free(node);
    node=NULL;

    assert(node == NULL);
    return node;
}


static bool invrep(pqueue q) {
    bool b = (q!=NULL);

    if (b && q->first !=NULL && q->size != 0)
    {
        unsigned int length = 1u;
        struct s_node *aux = q ->first;

        while (aux->next != NULL)
        {
            b = b && aux->priority <= aux->next->priority;
            aux = aux->next;
            length++;
        }

        b = b && q->size == length;        
    }
    

    return (b);
}

pqueue pqueue_empty(void) {
    pqueue q=malloc(sizeof(struct s_pqueue));
    q->size=0u;
    q->first=NULL;

    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    struct s_node *aux = q->first;
    struct s_node *aux2 = NULL;
    
    
    if (q->size == 0)
    {
        q->first = new_node;
    } else {
        
        while (aux != NULL && priority >= aux->priority) {

            aux2 = aux;

            aux = aux->next;
        }

        new_node->next = aux;

//agregue este if, porque sino el primer elemento que se cargaba siempre quedaba en la primera posicion
        if (aux2 != NULL) {
            
            aux2->next = new_node;

        } else {

            q->first = new_node;
        }

        
    }
    q->size++;
    
    assert(invrep(q));

    return q;
}

bool pqueue_is_empty(pqueue q) {
    
    return (q->first==NULL);
}

pqueue_elem pqueue_peek(pqueue q) {
    
    return q->first->elem;
}

unsigned int pqueue_peek_priority(pqueue q) {   
    
    return q->first->priority;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));

    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node * killme=q->first;
    q->first = q->first->next;
    --q->size;
    killme = destroy_node(killme);
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    struct s_node *node=q->first;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}
