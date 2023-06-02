#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 35, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(name_t), sizeof(unsigned int), sizeof(unsigned int), sizeof(data_t));

    // La suma de los miembros no coincide con el total. La suma es 38 y el total 40   
    // Asumo que debe ser por una necesidad de memoria para poder guardar los datos "juntos"

    // El tamaño de name NO depende del nombre. Siempre va a tener reservado 30 bytes por como esta definido (o el valor que se le de a NAME_MAXSIZE)
    // Esto porque esta definido como un arreglo de 30 chars 

    return EXIT_SUCCESS;
}

