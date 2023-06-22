#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void print_is_empty(list l)
{
    if (list_is_empty(l))
    {
        printf("La lista está vacía\n");
    }
    else
    {
        printf("La lista no está vacía\n");
    }
}

static void test_case1()
{
    list l = list_empty();
    print_is_empty(l);
    l = list_addl(l, 3);
    l = list_addl(l, 5);
    l = list_addl(l, 7);
    print_is_empty(l);
    printf("List length: %u\n", list_length(l));
    printf("List head: %u\n", list_head(l));
    list_print(l);
    l = list_addr(l, 12);
    printf("List length: %u\n", list_length(l));
    list_print(l);
    l = list_tail(l);
    printf("List length: %u\n", list_length(l));
    printf("List head: %u\n", list_head(l));
    list_print(l);
    l = list_tail(l);
    printf("List length: %u\n", list_length(l));
    printf("List head: %u\n", list_head(l));
    list_print(l);
    l = list_destroy(l);
}

/**
 * @brief Implementar un caso de prueba para la función list_greater_than
 *        Debe filtrar la lista por el mayor que y luego deberá
 *        llamar a list_greater_than_count para comparar el largo de la lista
 *        devuelta por list_greater_than con el resultado de
 *        list_greater_than_count.
 *
 */
static void test_case2()
{
    list l = list_empty();
    l = list_addl(l, 3);
    l = list_addl(l, 5);
    l = list_addl(l, 7);
    l = list_addl(l, 12);
    printf("Initial list: \n");
    list_print(l);

    list gtl = list_greater_than(l,6);
    printf("\nList after greater than 6:\n");
    list_print(gtl);

    printf("\nNow lets check list_greater_than_count!!\n");
    printf("List length: %u\n", list_length(gtl));
    printf("List_greater_than_count: %u\n", list_greater_than_count(l,6));

    l = list_destroy(l);
    gtl = list_destroy(gtl);
}

/**
 * @brief Implementar un caso de prueba para la función list_insert_at
 *        Se debe insertar un elemento en la posición 0 de la lista
 *        validar que se comporte como list_addl
 *
 */
static void test_case3()
{
    list l = list_empty();
    l = list_addl(l, 3);
    l = list_addl(l, 5);
    l = list_addl(l, 7);
    printf("Initial list: \n");
    list_print(l);

    printf("\nNow lets use list_insert_at as addl!!\n");
    l = list_insert_at(l,0,12);
    printf("\nNew list: \n");
    list_print(l);

    l = list_destroy(l);
}

/**
 * @brief Implementar un caso de prueba para la función list_insert_at
 *        Se debe insertar un elemento en la posición N-1 de la lista
 *        validar que se comporte como list_addr. La lista debe tener > 4 elems
 *
 */
static void test_case4()
{
    list l = list_empty();
    l = list_addl(l, 3);
    l = list_addl(l, 5);
    l = list_addl(l, 7);
    l = list_addl(l, 12);
    l = list_addr(l, 78905632);
    printf("Initial list: \n");
    list_print(l);

    printf("\nNow lets use list_insert_at as addr!!\n");
    l = list_insert_at(l,list_length(l),23);
    printf("\nNew list: \n");
    list_print(l);

    l = list_destroy(l);
}

/**
 * @brief Implementar un caso de prueba para la función list_insert_at
 *        Se debe insertar un elemento en alguna posición 0 < position < N-1
 *        La lista debe tener al menos 4 elementos
 *        Imprimir la lista
 *
 */

static void test_case5()
{
    list l = list_empty();
    l = list_addl(l, 3);
    l = list_addl(l, 5);
    l = list_addl(l, 7);
    l = list_addl(l, 12);
    l = list_addr(l, 78905632);
    printf("Initial list: \n");
    list_print(l);

    printf("\nNow lets use list_insert_at at the position 3!!\n");
    l = list_insert_at(l,3,23);
    printf("\nNew list: \n");
    list_print(l);

    l = list_destroy(l);
}

int main(void)
{
    printf("\n-----------Test case 1-----------\n");
    test_case1();
    printf("\n-----------Test case 2-----------\n");
    test_case2();
    printf("\n-----------Test case 3-----------\n");
    test_case3();
    printf("\n-----------Test case 4-----------\n");
    test_case4();
    printf("\n-----------Test case 5-----------\n");
    test_case5();
    
    return EXIT_SUCCESS;
}
