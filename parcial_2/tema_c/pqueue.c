#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    unsigned int size;
    struct s_node **array;
    priority_t min_prio;
};

struct s_node {
    pqueue_elem elem;
    struct s_node *next;
};

static struct s_node * create_node(pqueue_elem e) {
    struct s_node *new_node = malloc(sizeof(struct s_node));
    
    assert(new_node!=NULL);
    
    new_node->elem = e;
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
    bool b = (q != NULL);

    if (b && q->size != 0u && q->array != NULL){

        struct s_node *aux;

        unsigned int length = 0u;

        for (size_t i = 0; i <= q->min_prio; i++) {

            aux = q->array[i];

            while (aux != NULL) {

                aux = aux->next;

                length ++;
            }
        }

        b = b && length == q->size;
    }
    
    return b;
}

pqueue pqueue_empty(priority_t min_priority) {
    pqueue q=NULL;
    q = malloc(sizeof(struct s_pqueue));

    q->size = 0u;
    q->min_prio = min_priority;
    q->array = calloc(min_priority + 1, sizeof(struct s_node *));

    for (size_t i = 0; i <= min_priority; i++)
    {
        q->array[i] = NULL;
    }
     

    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, priority_t priority) {
    assert(invrep(q));

    struct s_node *new = create_node(e);
    struct s_node *aux = q->array[priority];
    
    if (q->array[priority] == NULL)
    {
        q->array[priority] = new;
    } else {
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = new;

    }
    ++q->size;

    assert(invrep(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));

    bool b = true;
    unsigned int i = 0u;

    while (b && i <= q->min_prio)
    {
        b = b && (q->array[i] == NULL);
        ++i;
    }
    

    return b;
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));

    pqueue_elem elem;
    unsigned int i = 0u;

    while (q->array[i] == NULL)     //aca confio en que el indice no se pasa, ya que antes esta el assert de que es no vacio
    {
        i++;
    }
    
    elem = q->array[i]->elem;

    return elem;
}

priority_t pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    
    priority_t peek_prio;
    unsigned int i = 0u;

    while (q->array[i] == NULL)     //aca confio en que el indice no se pasa, ya que antes esta el assert de que es no vacio
    {
        ++i;
    }
    
    peek_prio = i;
    
    return peek_prio;
}

size_t pqueue_size(pqueue q) {
    assert(invrep(q));
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    
    priority_t i = pqueue_peek_priority(q);

    struct s_node *kill_me = q->array[i];
    q->array[i] = q->array[i]->next;
    kill_me = destroy_node(kill_me); 
    --q->size;

    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));

    while(!pqueue_is_empty(q)){
        
        q = pqueue_dequeue(q);
    }

    free(q->array);

    free(q);

    q = NULL;

    return q;
}

