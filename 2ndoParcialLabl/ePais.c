#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ePais.h"
#include "informes.h"
#include "utn.h"






ePais* pais_new()
{
	   ePais* newPais = (ePais*) malloc(sizeof(ePais));   //asigna espacio en memoria dinamica

	    if(newPais != NULL)
	    {
	      newPais->id = 0;
	      strcpy(newPais->nombre, "");
	      newPais->infectados = 0;
          newPais->recuperados = 0;
          newPais->muertos = 0;

	    }

	    return newPais;
}


ePais* pais_newParametros(char* idStr,char* nameStr,char* recuStr, char* infStr, char* deathStr)
{

	ePais* newPais = pais_new();

	if(newPais != NULL && idStr != NULL && nameStr != NULL && recuStr != NULL && infStr != NULL && deathStr != NULL)
	{
			if(pais_setId(newPais, atoi(idStr)) == 1 ||
				(pais_setName(newPais,nameStr)) == 1 ||
				(pais_setRecu(newPais, atoi(recuStr)) == 1 ||
				pais_setInf(newPais,atoi(infStr))== 1 ||
                pais_setMuer(newPais, atoi(deathStr)) == 1))
			{

				pais_delete(newPais);
				newPais = NULL;

			}


	}

	return newPais;

}



void pais_delete(ePais* this)
{

    if(this != NULL)
    {
        free(this);

    }


}


int printPais(LinkedList* lista, int index)
{
	int todoOk = 1;

		ePais* pPais;
		int auxId;
		char auxName[20];
		int auxRecu;
		int auxInf;
		int auxDeaths;

		if(lista != NULL && index >= 0)
		{
			pPais = ll_get(lista, index);

			if(pais_getId(pPais, &auxId) == 0 &&
			   pais_getName(pPais, auxName) ==0 &&
			   pais_getRecu(pPais, &auxRecu) == 0 &&
			   pais_getInf(pPais, &auxInf) == 0 &&
                pais_getMuer(pPais, &auxDeaths)== 0)

			{
				printf("%-3d          %-10s                 %-3d                %-3d                %-3d        \n", auxId, auxName, auxRecu, auxInf, auxDeaths);
			}


		}
		else
		{
						printf("Error\n");
		}


	return todoOk;
}


void* assignEst(void* pais)
{

    ePais* auxPais = NULL;


    if(pais != NULL)
    {
        auxPais = (ePais*) pais;

        pais_setRecu(auxPais, getRandomRecu());   //asigna los recuperados aleatoriamente
        pais_setInf(auxPais, getRandomInf());       //asigna los infectados aleatoriamente
        pais_setMuer(auxPais, getRandomMuer());     //asigna los muertos aleatoriamente


    }

    return auxPais;

}


int getRandomRecu()
{

    int aleatorio;


   aleatorio = rand() %(50001 + 950000);     //toma el modulo de la suma entera, lo mismo para los otros


    return aleatorio;
}

int getRandomInf()
{

    int aleatorio;


   aleatorio = rand() %(40001 + 1960000);


    return aleatorio;
}

int getRandomMuer()
{

    int aleatorio;


   aleatorio = rand() %(1001 + 49000);


    return aleatorio;
}


int infecTripleRecu(void* pais)
{

    int auxReturn = 0;
    ePais* x;

    if(pais != NULL)
    {

        x = (ePais*) pais;

        if( x->infectados> (x->recuperados*3))   //triple
           {

                auxReturn = 1;

           }


    }


    return auxReturn;

}

int successFilter(void* pais)
{

    int auxReturn = 0;
    ePais* x;

    if(pais != NULL)
    {

        x = (ePais*) pais;

        if( x->muertos < 5000)  //muertos < 5000
           {

                auxReturn = 1;

           }


    }


    return auxReturn;

}



int sortCountryByInf(void* x, void* y)
{
	int ordenDevuelto = 0;
	int firstInf;
	int secondInf;

	pais_getInf(x,&firstInf);
	pais_getInf(y,&secondInf);


	if(firstInf>secondInf)
	{

		ordenDevuelto = 1;     //1 si firstinf < second inf

	}
	else if(firstInf<secondInf) //-1 si firstinf > secondinf
	{

		ordenDevuelto = -1;

	}



	return ordenDevuelto;
}





//setters

int pais_setId(ePais* this,int id)
{
	int todoOk = 1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		todoOk = 0;

	}

	return todoOk;

}


int pais_setName(ePais* this,char* name)
{

	int todoOk = 1;

	if(this != NULL && name != NULL)
	{
		strcpy(this->nombre, name);

		todoOk = 0;

	}

	return todoOk;


}

int pais_setRecu(ePais* this,int recu)
{
	int todoOk = 1;

	if(this != NULL)
	{
		this->recuperados = recu;
		todoOk = 0;

	}


	return todoOk;
}

int pais_setInf(ePais* this,int inf)
{
	int todoOk = 1;

	if(this != NULL)
	{

		this->infectados = inf;
		todoOk = 0;

	}

	return todoOk;
}

int pais_setMuer(ePais* this,int muer)
{
	int todoOk = 1;

	if(this != NULL)
	{

		this->muertos = muer;
		todoOk = 0;

	}

	return todoOk;
}

//getters

int pais_getId(ePais* this,int* id)
{
	int todoOk = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 0;

	}

	return todoOk;



}


int pais_getName(ePais* this,char* name)
{

	int todoOk = 1;

		if(this != NULL && name != NULL)
		{
			strcpy(name, this->nombre);
			todoOk = 0;

		}

		return todoOk;


}

int pais_getRecu(ePais* this,int* recu)
{

	int todoOk = 1;

		if(this != NULL && recu != NULL)
		{
			*recu = this->recuperados;
			todoOk = 0;

		}


		return todoOk;

}


int pais_getInf(ePais* this,int* inf)
{

	int todoOk = 1;

		if(this != NULL && inf != NULL)
		{

			*inf = this->infectados;
			todoOk = 0;

		}

		return todoOk;


}

int pais_getMuer(ePais* this,int* muer)
{

	int todoOk = 1;

		if(this != NULL && muer != NULL)
		{

			*muer = this->muertos;
			todoOk = 0;

		}

		return todoOk;


}



