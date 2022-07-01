#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	FILE* pFile;
	int retorno = -1;
	if(pArrayList != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			retorno = parser_PeliculasFromText(pFile,pArrayList);
			fclose(pFile);
		}else{
			printf("Algo revento mientras se parceaba");
		}
	}else{
		printf("\n algo revento en la validacion pArrayList != NULL ");
	}
	return retorno;
}

int controller_ListPeliculas(LinkedList* pArrayList)
{
	int tam;
	int i;
	ePeliculas* eAux=NULL;
	if(pArrayList!=NULL)
	{
		tam=ll_len(pArrayList);
		if (tam>0)
		{
			printf("\n\n****Listado ****\n");
			for (i=0; i < tam; i++)
			{
				eAux=ll_get(pArrayList,i);
				if(eAux!=NULL)
				{
					Peliculas_PrintConString(eAux);
				}
			}
		}
		else
		{
			printf("\n\n\nEl sitema no posee datos\n");
		}
	}
	system("PAUSE()");
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int ret = -1;
    FILE* pFileAux = NULL;
    ePeliculas *Peliculas = NULL;

    int auxId;
    char auxPeliculas[200];
    char Genero[200] ;
    int Duracion;


    if(path != NULL && pArrayList != NULL)
    {
        pFileAux = fopen(path, "w");
        if(pFileAux != NULL)
        {
            for(int i =0; i<ll_len(pArrayList); i++)
            {
            	Peliculas = ll_get(pArrayList, i);

                	 if(Peliculas_getId(Peliculas,&auxId) &&
                        Peliculas_getPeliculas(Peliculas,auxPeliculas) &&
                        Peliculas_getGenero(Peliculas,Genero) &&
						Peliculas_getDuracion(Peliculas,&Duracion)
                      )
                {
                    fprintf(pFileAux,"%d , %s , %s , %d  \n", auxId,auxPeliculas,Genero,Duracion );
                    ret = 0;
                }
                else
                {
                    Peliculas_delete(Peliculas);
                }
            }
        }
        fclose(pFileAux);
    }
    return ret;
}

int controller_sortPeliculas(LinkedList* pArrayList)
{
    int ret = -1;

    if(pArrayList != NULL)
    {
        ll_sort(pArrayList, Peliculas_compararPorNombre, 1);
        ret=0;
    }
    return ret;
}


int mapeadoPeliculas(void* this)
{
	int auxDuracion;


	int ret = -1;


	if (this != NULL) {

		this=(ePeliculas*)this;

		Peliculas_getDuracion((ePeliculas*) this, &auxDuracion);


		if (auxDuracion >= 100 && auxDuracion <= 240)
		{

			Peliculas_setDuracion((ePeliculas*) this,auxDuracion);

		}
	}
	return ret ;
}


int controller_saveMappeado(LinkedList* pArrayList)
{
    int ret = -1;

    if( pArrayList != NULL)
    {
            ll_map(pArrayList, mapeadoPeliculas);
            ret = 1 ;
    }
    return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////



int Peliculas_Genero1 (void* this)
{
    int ret = 0;
    int auxGenero;

    if(this!= NULL)
    {
        Peliculas_getGenero((ePeliculas*)this, &auxGenero);

        if(auxGenero ==1 )
        {
            ret=1;
        }
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////

int Peliculas_Mayores100 (void* this)
{
    int ret = 0;
    int auxDuracion;

    if(this!= NULL)
    {
        Peliculas_getDuracion((ePeliculas*)this,&auxDuracion);
        if(auxDuracion > 100)
        {
            ret=1;
        }
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////

int controller_informes( LinkedList* pArrayList)
{
    int ret = -1;
    int cantidadVentasMayores100;
    int cantidadGenero1 ;

    if(pArrayList != NULL)
    {

            cantidadVentasMayores100 = ll_count(pArrayList,Peliculas_Mayores100);
            cantidadGenero1 = ll_count(pArrayList,Peliculas_Genero1);

            printf("\n----INFORMES-----\n");
            printf("\nCantidad de Peliculas con el Duracion mayor a  100 : %d\n",cantidadVentasMayores100);
            printf("\nCantidad de Peliculas del Genero 1 : %d\n",cantidadGenero1);

            ret= 0 ;
        }
    return ret;
}


