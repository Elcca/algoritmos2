#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter new = NULL;
    new = malloc(sizeof(counter));
    new->count = 0;
    return new;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    bool b = c->count == 0;
    return b;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count = c->count - 1;
}

counter counter_copy(counter c) {
    counter copy=NULL;
    copy = malloc(sizeof(counter));
    copy->count = c->count;
    return copy;
}

void counter_destroy(counter c) {
    free(c);
}
