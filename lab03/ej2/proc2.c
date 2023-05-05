#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x>=0)
    {
        *y=x;
    } else {
        *y=-x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    int *p=&res;

    a=-10;
    absolute(a,p);
    printf("%d\n",res);

    return EXIT_SUCCESS;
}

//en c todos los parametros son in/out, aunque en este caso solo cumple la funcion
//de out, ya que nunca se lee lo que habia previamente en la variable. 
//con x pasa lo contrario

