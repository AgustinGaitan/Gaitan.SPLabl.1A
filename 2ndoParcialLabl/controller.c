#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ePais.h"
#include "utn.h"
#include "controller.h"
#include "parser.h"
#include "menu.h"


int controller_loadFromText(LinkedList* pArrayCountry) //funcion que se llama desde el main
{

    system("cls");
	int todoOk = 1;
	char path;
	FILE* pf;


	printf("Ingrese el nombre del archivo.\nRecuerde ingresar la extension: ");
	fflush(stdin);
	gets(&path);

      pf =  fopen(&path,"r");   // se abre la carpeta para lectura 'r'

            if(pf != NULL )
             {
                 if(!(parser_CountryFromText(pf,pArrayCountry))) //se parsea de string a su debido tipo
                    {

                        printf("Archivo encontrado.\n\n"); //todook
                        todoOk = 0;

                    }
             }
             else
            {
                 printf("Error.Archivo no encontrado.\n");
            }
             fclose(pf);


    return todoOk;
}




int controller_saveAsText(char* path , LinkedList* pArrayCountry)
{
        int todoOk = 1;
		FILE* pf;
		char auxName[20];
		int auxId;
		int auxRecu;
		int auxInf;
		int auxMuer;
		int tam = ll_len(pArrayCountry); // se le asigna el tamaño
		ePais* pPais;


			pf = fopen(path, "w");                   //se abre el archivo en modo write "w"


			if(pf != NULL)
			{
                fprintf(pf,"Id,Nombre,Recuperados,Infectados,Muertos\n");
				for(int i = 0; i < tam; i++)  //recorre para cada pais
				{
					pPais = ll_get(pArrayCountry, i);  //obtiene cada pais mediante el indice

					if((pais_getId(pPais, &auxId)==0) &&
					   (pais_getName(pPais, auxName)==0) &&
					   (pais_getRecu(pPais, &auxRecu)==0) &&  // si esta todo ok pasa a imprimir los paises
					   (pais_getInf(pPais, &auxInf)==0) &&
                        (pais_getMuer(pPais,&auxMuer)== 0))
					{

						fprintf(pf, "%d,%s,%d,%d,%d\n", auxId, auxName, auxRecu, auxInf,auxMuer);  //imprime a los paises en el archivo
						todoOk = 0;
					}
				}
				fclose(pf);
				printf("Archivo guardado.\n");
			}


	    return todoOk;
}


int controller_assignStats(LinkedList* pArrayCountry)
{
    system("cls");
    int todoOk = 1;
    LinkedList* listaConAsign = ll_newLinkedList();    //nueva lista

    if(pArrayCountry != NULL)
    {

          listaConAsign = ll_map(pArrayCountry,assignEst);  //mapeo/asignacion

          if(listaConAsign != NULL)
            {

              printf("Estadisticas asignadas con exito.\n");

                ll_deleteLinkedList(listaConAsign);  //se borra
                todoOk = 0;

          }




    }


    return todoOk;
}

