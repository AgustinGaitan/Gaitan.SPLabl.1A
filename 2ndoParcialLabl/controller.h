#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED


/** \brief Carga el archivo
 *
 * \param lista
 * \return (1) si hubo error (0) si fue exitoso
 *
 */



int controller_loadFromText(LinkedList* pArrayCountry);



/** \brief Guarda el archivo
 *
 * \param ruta del archivo
 * \param lista
 * \return (1) si hubo error (0) si fue exitoso
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayCountry);



/** \brief Le asigna a los paises cantidades de muertos,infect, y recuperados
 *
 * \param lista
 * \return (1) si hubo error (0) si fue exitoso
 *
 */
int controller_assignStats(LinkedList* pArrayCountry);





