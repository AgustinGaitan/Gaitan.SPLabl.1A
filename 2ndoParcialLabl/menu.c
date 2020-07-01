#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"


int menu()
{

    int opcion;

    printf(" 1. Cargar archivo.\n");
    printf(" 2. Imprimir lista.\n");
    printf(" 3. Asignar estadisticas.\n");
    printf(" 4. Filtrar por paises exitosos.\n");
    printf(" 5. Filtrar por paises en el horno.\n");
    printf(" 6. Ordenar por nivel de infeccion.\n");
    printf(" 7. Mostrar mas castigado\n");
    printf(" 8. Salir\n\n");


    utn_getEntero(&opcion,5,"Ingrese la opcion que desea: ", "Error. Ingrese una opcion valida.\n",1,8);

    return opcion;

}



