/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    bool res = (x.rank<=y.rank);
    return res;
}


void swap (player_t a[], unsigned int i, unsigned int j) {
    player_t aux;
    aux = a[i];
    a[i]=a[j];
    a[j]=aux;
}


static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv=izq;
    int i=izq+1;
    int j=der;
    while (i<=j)
    {   
        if (goes_before(a[i],a[ppiv]))
        {
            i++;
        } else {
            if (goes_before(a[ppiv],a[j]))
            {
                j=j-1;
            } else {
                swap(a,i,j);
                i++;
                j=j-1;
            }
            
        }
        
    }

    swap(a,ppiv,j);
    ppiv=j;

    return ppiv;
}


bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = 0u;
    if (der>izq)
    {
        ppiv = partition(a,izq,der);
        quick_sort_rec (a,izq,(ppiv==0) ? 0u : ppiv-1);
        quick_sort_rec (a,ppiv+1,der);
    }
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


