#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pair.h"


pair_t pair_new (int x, int y)
{
    pair_t res;
    res.fst = x;
    res.snd = y;

    return res;
}

int pair_first(pair_t p)
{
    int first = p.fst;
    
    return first;
}

int pair_second(pair_t p)
{
    int second = p.snd;

    return second;
}

pair_t pair_swapped(pair_t p)
{
    int aux = p.fst;
    p.fst = p.snd;
    p.snd = aux;

    return p;
}

pair_t pair_destroy(pair_t p)
{
    return p;
}

// La implementacion no logra encapsulamiento, ya que se pueden cambiar los valores de un par sin usar
// las funciones dadas por la especificacion.
// por ejemplo; si tenemos un par p, y hacemos p.fst = 1, estamos cambiando el primer valor del par
// sin usar la funcion pair_first, que se supone que hay que usar. 