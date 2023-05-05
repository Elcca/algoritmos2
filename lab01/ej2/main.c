/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_stdin(int array[], unsigned int max_size) {
    
    printf("ingrese primero el tamaño del arreglo, luego los elementos que quiere.\n"
           "cuando termine de ingresar los datos presione ctrl+d para terminar, y ver el arreglo\n\n");
    

    FILE *datos;
    datos = stdin;

    unsigned int length;
    fscanf(datos, "%u", &length);
    printf("\n");
    
    for (size_t i = 0; i < max_size; i++) {

        fscanf(datos , "%d" , &array[i]);
    }  

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


int main() {
    
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
