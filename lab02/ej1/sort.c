#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    while (i>0 && goes_before(a[i], a[i-1])){
        swap (a, i, i-1);
        i=i-1;
    }
}

void insertion_sort(int a[], unsigned int length) {
    int copy[length];

    for (unsigned int i = 1u; i < length; ++i) {
        copy[i-1]=a[i-1];
        assert (array_is_sorted(copy,i));
        insert(a, i);
    }
}
