#ifndef EPAIS_H_INCLUDED
#define EPAIS_H_INCLUDED

typedef struct
{

    int id;
    char nombre[20];
    int recuperados;
    int infectados;
    int muertos;


}ePais;

#endif // EPAIS_H_INCLUDED


/** \brief Hace un nuevo pais
 *
 * \param
 * \param
 * \return Nuevo pais
 *
 */


ePais* pais_new();

/** \brief Dentro se utilizan los setters
 *
 * \param id en string
 * \param nombre en string
 * \param recuperados en string
 * \param infectados en string
 * \param muertos en string
 * \return
 *
 */


ePais* pais_newParametros(char* idStr,char* nameStr,char* recuStr, char* infStr, char* deathStr);

void pais_delete(ePais* this);

/** \brief Muestra un pais
 *
 * \param lista del linked list
 * \param  indice
 * \return (1) si hubo error (0) si salio todo bien
 *
 */


int printPais(LinkedList* lista, int index);

/** \brief setea el id
 *
 * \param lista
 * \param id
 * \return (1) si hubo error (0) si salio todo bien
 *
 */


int pais_setId(ePais* this,int id);

/** \brief setea el nombre
 *
 * \param lista
 * \param nombre
 * \return (1) si hubo error (0) si salio todo bien
 *
 */


int pais_setName(ePais* this,char* name);

/** \brief setea la cant de recuperados
 *
 * \param lista
 * \param tipo
 * \return (1) si hubo error (0) si salio todo bien
 *
 */


int pais_setRecu(ePais* this,int recu);

/** \brief setea los infect
 *
 * \param lista
 * \param time
 * \return (1) si hubo error (0) si salio todo bien
 *
 */



int pais_setInf(ePais* this,int inf);

/** \brief obtiene el id
 *
 * \param lista
 * \param id
 * \return (1) si hubo error (0) si salio todo bien
 *
 */

 int pais_setMuer(ePais* this,int muer);



int pais_getId(ePais* this,int* id);

/** \brief obtiene el nombre
 *
 * \param lista
 * \param nombre
 * \return (1) si hubo error (0) si salio todo bien
 *
 */

int pais_getName(ePais* this,char* name);

/** \brief obtiene la cant de recuperados
 *
 * \param lista
 * \param recuperados
 * \return (1) si hubo error (0) si salio todo bien
 *
 */


int pais_getRecu(ePais* this,int* recu);

/** \brief obtiene la cantidad de  infectados
 *
 * \param lista
 * \param infectados
 * \return (1) si hubo error (0) si salio todo bien
 *
 */



int pais_getInf(ePais* this,int* inf);

/** \brief obtiene la cant de muertos a los paises
 * \param muertos
 * \return puntero a void
 *
 */

 int pais_getMuer(ePais* this,int* muer);


/** \brief asigna estadisticas a paises
 *
 * \return puntero a void
 *
 */

void* assignEst(void* pais);

/** \brief numero random
 *
 * \return numero random
 *
 */


int getRandomRecu();
int getRandomInf();
int getRandomMuer();

/** \brief filtra a los que tengan como infectados triple de recuperados
 *
 * \param pais
 * \return (0) si no hay coincidencias (1) si se encontraron iguales
 *
 */


int infecTripleRecu(void* pais);

/** \brief filtra por paises si tienen menos de 5000 muertos
 *
 * \param pais
 * \return (0) si no hay coincidencias (1) si se encontraron iguales
 * \return
 *
 */


int successFilter(void* pais);




/** \brief Ordena por infectados
 *
 * \param inf1
 * \param inf2
 * \return (0) si no se encontro (1) si inf1 es mayor a inf2
 *                               (-1) si inf2 es mayor a inf1
 *
 */


int sortCountryByInf(void* x, void* y);



