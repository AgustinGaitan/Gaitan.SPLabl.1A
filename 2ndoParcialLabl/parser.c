#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "ePais.h"



int parser_CountryFromText(FILE* pFile , LinkedList* pArrayCountry)
{
	int todoOk = 1;
	ePais* pPais;

	char auxId[100];
	char auxName[20];
	char auxRecu[1000];
	char auxInfec[1000];
	char auxDeath[100];
	int cant;




    if(pFile != NULL)
    {

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName, auxRecu, auxInfec,auxDeath);
        do
        {


            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName, auxRecu,auxInfec, auxDeath);
            if(cant == 5)
            {

                pPais = pais_newParametros(auxId,auxName,auxRecu,auxInfec,auxDeath); //le pasa los parametros.

                if(pPais != NULL)
                {

                    ll_add(pArrayCountry, pPais);

                    todoOk = 0;

                }

            }


        }while(!feof(pFile));

    }

    return todoOk;


}
