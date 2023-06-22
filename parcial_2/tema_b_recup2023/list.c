#include "list.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct _list
{
    struct _node* head;
    ListSize size;
};

struct _node
{
    elem e;
    struct _node* next;
};

/**
 * @brief Invariante de represetación
 *
 * @param l Lista
 * @return true Si l es una lista válida
 * @return false Si l NO es una lista válida
 */
static bool invrep(list l)
{
    // COMPLETE AQUI
    return l != NULL || l == NULL;  // Para que compile, REMOVER
}

/**
 * @brief Crea un nodo de la lista nuevo
 *
 * @param e Elemento que contendrá el nodo
 * @return struct _node* Nuevo nodo creado o NULL si no hay memoria
 */
static struct _node* create_node(elem e)
{
    struct _node* res = malloc(sizeof(struct _node));
    if (res != NULL)
    {
        res->e = e;
        res->next = NULL;
    }
    return res;
}

/**
 * @brief Destruye el nodo node
 *
 * @param node Nodo a ser destruido
 * @return struct _node* Devuelve NULL si el nodo se destruyó correctamente
 */
static struct _node* destroy_node(struct _node* node)
{
    if (node != NULL)
    {
        free(node);
        node = NULL;
    }
    assert(node == NULL);
    return node;
}

list list_empty()
{
    list res = malloc(sizeof(struct _list));
    res->head = NULL;
    res->size = 0u;

    assert(invrep(res));
    return res;
}

list list_addl(list l, elem e)
{
    assert(invrep(l));
    
    struct _node *new_node = create_node(e);  
    new_node->next = l->head;
    l->head = new_node;
    l->size++;

    assert(invrep(l));
    return l;
}

list list_addr(list l, elem e)
{
    assert(invrep(l));
    
    struct _node *new_node = create_node(e); 
    struct _node *aux = l->head;

    if (aux == NULL)
    {
        l->head = new_node;
    } else {
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new_node;
    }
    
    l->size++;

    assert(invrep(l));
    return l;
}

bool list_is_empty(list l)
{
    assert(l != NULL && invrep(l));
    
    bool b = l->head==NULL;

    return b;
}

elem list_head(list l)
{
    assert(l != NULL && invrep(l) && !list_is_empty(l));
    
    elem e = l->head->e;
    
    return e;  
}

list list_tail(list l)
{
    assert(!list_is_empty(l));
    
    struct _node *killme = l->head;

    l->head = l->head->next;

    killme = destroy_node(killme);

    l->size--;

    return l;
}

ListSize list_length(list l)
{
    assert(l != NULL);
    
    return l->size;
}

void list_print(list l)
{
    printf("Your list is: [");

    struct _node *aux = l->head;
    while (aux->next != NULL){
        printf("%d, ", aux->e);
        aux = aux->next;
    }
    printf("%d]\n", aux->e);    
}

list list_destroy(list l)
{
    assert(l != NULL && invrep(l));
    
    struct _node *aux = l->head;
    struct _node *killme = NULL;
    while(aux != NULL){
        killme = aux;
        aux = aux->next;

        killme = destroy_node(killme);
    }
    free(l);
    l=NULL;

    return l;
}

/* Funciones Anexas */

list list_greater_than(list l, unsigned int n)
{
    list new = list_empty();
    struct _node *aux = l->head;

    while (aux != NULL){
        if (aux->e > n)
        {
            new = list_addr(new,aux->e);    
        }
        aux = aux->next;
    }
    
    return new;
}

unsigned int list_greater_than_count(list l, unsigned int n)
{
    unsigned int count = 0u;
    struct _node *aux = l->head;

    while (aux != NULL){
        if (aux->e > n)
        {
            count++;    
        }
        aux = aux->next;
    }
    
    return count;
}

list list_insert_at(list l, unsigned int position, elem e)
{
    assert(position <= list_length(l));

    struct _node *aux = l->head;
    struct _node *aux2 = NULL;
    struct _node *new_node = create_node(e);
    unsigned int count = 0u;

    while (aux != NULL && count < position)
    {
        aux2 = aux;
        aux = aux->next;
        count++;
    }
    
    new_node->next = aux;

    if (aux2 != NULL){
        
        aux2->next = new_node;
    } else {
        l->head = new_node;
    }
    
    return l;
}