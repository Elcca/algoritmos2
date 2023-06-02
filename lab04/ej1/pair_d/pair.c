#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pair.h"

struct s_pair_t {
    int fst;
    int snd;
};


pair_t pair_new(int x, int y)
{
    pair_t pairp = NULL;
    pairp = malloc(sizeof(pair_t));
    pairp->fst = x;
    pairp->snd = y;
    
    return pairp;
}

elem pair_first(pair_t p)
{   
    assert(p!=NULL);
    int first = p->fst;
    
    return first;
}

elem pair_second(pair_t p)
{   
    assert(p!=NULL);
    int second = p->snd;
    
    return second;
}

pair_t pair_swapped(pair_t p)
{
    assert(p!=NULL);
    pair_t new = NULL;
    new = malloc(sizeof(pair_t));
    new->fst = p->snd;
    new->snd = p->fst;

    return new;
}

pair_t pair_destroy(pair_t p)
{
    free(p);
    return p;
}