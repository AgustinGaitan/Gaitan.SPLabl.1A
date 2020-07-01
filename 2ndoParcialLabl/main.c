#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "controller.h"
#include "menu.h"
#include "ePais.h"
#include "informes.h"

int main()
{
    char confirm;
    LinkedList* list = ll_newLinkedList();
    int flag = 0;
    srand(time(NULL));

       do
       {

            switch(menu())
            {

                 case 1:
                     flag = 0;
                        if(!flag)
                        {

                            controller_loadFromText(list);
                            flag = 1;

                        }

                    break;
                 case 2:
                     if(flag)
                     {
                         controller_ListCountry(list);

                     }
                     else
                     {

                         printf("Debe cargar un archivo.\n");

                     }

                    break;
                 case 3:
                     if(flag)
                     {

                       controller_assignStats(list);

                     }
                     else
                     {

                         printf("Debe cargar un archivo.\n");

                     }

                    break;
                 case 4:
                     if(flag)
                     {
                        controller_SuccessFilter(list);
                     }
                     else
                    {

                        printf("Debe cargar un archivo\n");

                    }


                    break;
                 case 5:
                     if(flag)
                     {

                         controller_countryAlHorno(list);

                     }
                    else
                       {

                           printf("Debe cargar un archivo\n");

                       }
                    break;
                 case 6:

                        if(flag)
                        {
                           controller_sortInfectionLevel(list);

                        }
                        else
                        {

                        printf("Debe cargar un archivo\n");

                        }

                    break;
                 case 7:
                     if(flag)
                     {
                        controller_countryMasCastigado(list);

                     }
                     else
                     {

                         printf("Debe cargar un archivo primero\n");

                     }

                    break;
                    case 8:

                       printf("Desea salir? s/n : ");
                       fflush(stdin);
                       scanf("%c", &confirm);

                    break;

            }

            system("pause");
            system("cls");

        }while(confirm != 's');


        ll_deleteLinkedList(list);


    return 0;
}
