//gcc -Wall -Werror -Wextra -pedantic -std=c99 -c fixstring.c
//gcc -Wall -Werror -Wextra -pedantic -std=c99 -c main.c
//gcc -Wall -Werror -Wextra -pedantic -std=c99 fixstring.o main.o -o ej0

#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i = 0u;
    while (s[i]!= '\0')
    {
        i++;
    }
    i++;
    
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    int i=0;
    bool res;
    res = fstring_length(s1)==fstring_length(s2);
    while ((s1[i] !='\0')  && res)
    {
        res = res && (s1[i]==s2[i]);
        i++;    
    }
    return res;  
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i=0;
    bool res;

    
    while (s1[i]==s2[i] && s1[i]!='\0')
    {
        i++;    
    }

    if(s2[i]!='\0'){
        res = s1[i]<s2[i];
    } else {
        res = false;
    }
    

    return res;
}

