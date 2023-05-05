#include "array_helpers.h"

#include "mybool.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    
    FILE *datos;
    datos = fopen(filepath, "r");

    int length;
    fscanf(datos, "%d", &length);
    
    for (size_t i = 0; i < max_size; i++) {

        fscanf(datos , "%d" , &array[i]);
        
    }  
    
    fclose(datos);

    return length;

}

void array_dump(int a[], unsigned int length) {
    if (length<=0)
    {
        printf("[]\n");
    } else {
        printf("[ ");

        for (size_t i = 0; i < length - 1; i++) {

            printf("%d, " , a[i]);

        }
        printf("%d]\n" , a[length-1]);

    }
    
}

mybool array_is_sorted(int a[], unsigned int length) {
    mybool res;
    res=true;

    for (size_t i = 0; i < (length-1); i++)
    {
        res=(res && (a[i]<a[i+1]));
    
    }

    return res;
}