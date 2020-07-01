#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "LinkedList.h"



#endif // INFORMES_H_INCLUDED


/** \brief lista a los paises
 *
 * \param lista
 * \return (1) si hubo error (0) si todo salio bien
 *
 */


int controller_ListCountry(LinkedList* pArrayCountry);

/** \brief lista a los paises mas exitosos y guarda archivo
 *
 * \param lista
 * \return (1) si hubo error (0) si todo salio bien
 *
 */

int controller_SuccessFilter(LinkedList* pArrayCountry);

/** \brief lista a los paises de orden descendente con respecto a los infectados
 * \param lista
 * \return (1) si hubo error (0) si todo salio bien
 *
 */

int controller_sortInfectionLevel(LinkedList* pArrayCountry);

/** \brief lista a los paises que tengan la cantidad de inf x3 a los recup y guarda archivo
 *
 * \param lista
 * \return (1) si hubo error (0) si todo salio bien
 *
 */

int controller_countryAlHorno(LinkedList* pArrayCountry);

/** \brief muestra que pais fue el mas castigado
 *
 * \param lista
 * \return (1) si hubo error (0) si todo salio bien
 *
 */

int controller_countryMasCastigado(LinkedList* pArrayCountry);


