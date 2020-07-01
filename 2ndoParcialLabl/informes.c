#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
#include "controller.h"
#include "ePais.h"
#include "menu.h"




int controller_SuccessFilter(LinkedList* pArrayCountry)
{
    system("cls");
    int todoOk = 1;
    LinkedList* filteredList = ll_newLinkedList();

    filteredList = ll_filter(pArrayCountry, successFilter);

        if(controller_ListCountry(filteredList))
        {

           printf("No hay paises que mostrar.\n");

        }

         controller_saveAsText("paisesExitosos.csv",filteredList);


        printf("Si no aparece ningun pais, significa que no hay paises exitosos.\n\n");










   return todoOk;

}


int controller_ListCountry(LinkedList* pArrayCountry)
{
    system("cls");
	int todoOk = 1;
	int tam = ll_len(pArrayCountry);  //se le asigna el tamaño


		if(pArrayCountry != NULL)
		{
			printf("Id         Nombre            Recuperados               Infectados            Muertos\n\n");

			for(int i = 0; i < tam; i++)
			{

					printPais(pArrayCountry,i);  //muestra uno por uno
                    todoOk = 0;
			}
		}

			else
			{
				printf("No hay paises.\n");
			}




    return todoOk;
}




int controller_sortInfectionLevel(LinkedList* pArrayCountry)
{
    system("cls");
    int todoOk = 1;
    LinkedList* sortedList = ll_newLinkedList();

    sortedList = ll_clone(pArrayCountry);

        ll_sort(sortedList,sortCountryByInf,0);

        if(controller_ListCountry(sortedList))
        {

            printf("\nPaises ordeandos con exito.\n\n");
            todoOk = 0;
        }


    return todoOk;
}


int controller_countryAlHorno(LinkedList* pArrayCountry)
{

     system("cls");
    int todoOk = 1;
    LinkedList* filteredList = ll_newLinkedList();

    filteredList = ll_filter(pArrayCountry, infecTripleRecu);

    if(controller_ListCountry(filteredList))
    {


        printf("No hay paises que mostrar\n");

    }

    controller_saveAsText("paisesAlHorno.csv",filteredList);

    printf(" Si no aparece ningun pais, significa que no hay paises con susodichas caracteristicas\n\n");


   return todoOk;



}



int controller_countryMasCastigado(LinkedList* pArrayCountry)
{
    system("cls");

    int flag = 0;
    int todoOk = 1;
    int mayorCantidad;
    int auxMuer;
    char auxNombre[20];
    int tam;
     ePais* auxPais = NULL;


    if(pArrayCountry != NULL)
    {
        tam = ll_len(pArrayCountry);
        for(int i = 0 ; i < tam ; i++)
        {
            auxPais = (ePais*) ll_get(pArrayCountry, i);
            pais_getMuer(auxPais, &auxMuer);

            if(flag == 0 || auxMuer > mayorCantidad)
            {
                    mayorCantidad = auxMuer;
                    pais_getName(auxPais, auxNombre);
                    flag = 1;
                    todoOk = 0;
            }
        }

        printf("Pais mas castigado :\n   %10s\n", auxNombre);
        printf("Cantidad de muertes:\n   %10d\n", mayorCantidad);
    }





    return todoOk;

}
