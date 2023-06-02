#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"




int main (void){
    stack s = stack_empty();
    stack aux;
    unsigned int input = 1;
    stack_elem push; 

    printf("para usar el programa:\n");
    printf("  0 para terminar la ejecucion\n");
    printf("  1 para agregar un elemento (push)\n");
    printf("  2 para eliminar la cima (pop)\n");
    printf("  3 para ver el tamaño del stack (size)\n");
    printf("  4 para devolver la cima (top)\n");
    printf("  5 para saber si el arreglo es vacio (is empty)\n");
    printf("  6 ver el stack\n \n");

    while (input !=0) {
        printf("ingrese lo que quiere hacer: \n");
        scanf("%u\n", &input);

        if (input == 1)
        {
            printf("ingrese el elemento que quiere agregar: \n");
            scanf("%d\n", &push);
            stack_push(s, push);
            printf("elemento agregado \n \n");

        } else {
            if (input == 2)
            {
                printf("cima eliminada \n \n");

            } else {
                if (input == 3)
                {
                    printf("el tamaño del stack es: %u \n \n", stack_size(s));
                } else {
                    if (input == 4)
                    {
                        printf("la cima es: %d \n \n", stack_top(s));

                    } else {
                        if (input == 5)
                        {
                            if(stack_is_empty(s)){
                                printf("true \n \n");
                            } else {
                                printf("false \n \n");
                            }
                        } else {
                            if (input == 6)
                            {
                                aux = s;
                                while (!stack_is_empty(aux))
                                {
                                    printf("%d ", stack_top(aux));
                                    aux = stack_pop(aux);
                                }
                                printf("\n \n");
                                
                            } else {
                                printf("no es un input valido \n");
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
}