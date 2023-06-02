#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef struct  _list * list;
typedef int list_elem;

/*constructors*/
list empty(void);
/*
    create a new empty list
*/

list addl(list l, list_elem e);
/*
    adds the new element e at the left of the list
*/





/*operations*/
bool is_empty(list l);
/*
    returns true if l is an empty list, false otherwise
*/

list_elem head(list l);
/*
    returns the first element of the list
    PRE: !is_empty(l)
*/

list tail (list l);
/*
    deletes the first elemen of l
    PRE: !is_empty(l)
*/

void destroy_list (list l);
/*
    frees space in memory if necessary
*/

list addr (list l, list_elem e);
/*
    adds e at the end of l
*/

unsigned int length (list l);
/*
    returns the amount of elements in l
*/

list concat (list l, list l0);
/*
    adds l0 ath the end of l
*/

list_elem index (list l, unsigned int n);
/*
    returns the element in the position n
    PRE: length(l) > n
*/

list take (list l, unsigned int n);
/*
    returns a list with the first n elements of l
*/

list drop (list l, unsigned int n);
/*
    deletes the fisrt n elements of l
*/

list copy_list (list l);
/*
    returns a copy of l
*/

#endif