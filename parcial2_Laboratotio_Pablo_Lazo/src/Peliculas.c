/*
 * Peliculas.c
 *
 *  Created on: 1 jul. 2022
 *      Author: USUARIO
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Peliculas.h"
#include "LinkedList.h"

ePeliculas* Peliculas_new()
{
	ePeliculas* this=(ePeliculas*) malloc(sizeof(ePeliculas));
	return this;
}

ePeliculas* Peliculas_newParametros(char* idStr,char* Peliculas,char* Genero, char* Duracion)
{
	ePeliculas* this=Peliculas_new();

		if(this!=NULL)
		{
			Peliculas_setId(this,atoi(idStr));
			Peliculas_setPeliculas(this,Peliculas);
			Peliculas_setGenero(this,Genero);
			Peliculas_setDuracion(this,atoi(Duracion));


		}
		return this;

}

int Peliculas_delete(ePeliculas* this)
{
	int ret=0;
	if(this!=NULL)
	{
		free(this);
		ret=1;
	}
	return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

int Peliculas_setId(ePeliculas* this,int id)
{
	int ret=0;
	static int maxId=0;
	if (this!=NULL)
	{
		if(id<0)
		{
			maxId++;
			this->id=maxId;
		}
		else
		{
			if(id>maxId)
			{
				maxId=id;
			}
			this->id=id;
		}
		ret=1;
	}
	return ret;
}

int Peliculas_getId(ePeliculas* this,int* id)
{
	int ret=0;
		if (this!=NULL && id !=NULL)
		{
			*id=this->id;
			ret=1;
		}
		return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int Peliculas_setPeliculas(ePeliculas* this,char* Peliculas)
{
	int ret=0;
	if (this!=NULL && Peliculas!=NULL)
	{
		strcpy(this->Peliculas,Peliculas);
		ret=1;
	}
	return ret;
}

int Peliculas_getPeliculas(ePeliculas* this,char* Peliculas)
{
	int ret=0;
	if (this!=NULL && Peliculas!=NULL)
		{
			strcpy(Peliculas,this->Peliculas);
			ret=1;
		}
		return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int Peliculas_setGenero(ePeliculas* this,char* Genero)
{
	int ret=0;
	if (this!=NULL && Genero!=NULL)
	{
		strcpy(this->Genero,Genero);
		ret=1;
	}
	return ret;
}

int Peliculas_getGenero(ePeliculas* this,char* Genero)
{
	int ret=0;
	if (this!=NULL && Genero!=NULL)
		{
			strcpy(Genero,this->Genero);
			ret=1;
		}
		return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int Peliculas_setDuracion(ePeliculas* this,int Duracion)
{
	int ret=0;
	if (this!=NULL && Duracion>=0)
	{
		this->Duracion=Duracion;
		ret=1;
	}
	return ret;
}


int Peliculas_getDuracion(ePeliculas* this,int* Duracion)
{
	int ret=0;
	if (this!=NULL && Duracion!=NULL)
	{
		*Duracion=this->Duracion;
		ret=1;
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////////////////////////////////////////////////////

int Peliculas_Print(ePeliculas* this)
{
	int ret=0;
	int id;
	char Peliculas[128];
	char Genero[128];
	int Duracion;


	if (this!=NULL)
	{
		if(Peliculas_getId(this,&id) && Peliculas_getPeliculas(this,Peliculas) && Peliculas_getGenero(this,Genero) && Peliculas_getDuracion(this,&Duracion))
		{
			printf("ID: %d	||| Peliculas: %s  ||| Genero: %s ||| Duracion: $%d |||",
					id,Peliculas,Genero,Duracion);
			ret=1;
		}
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int Peliculas_PrintConString(ePeliculas* this)
{
	int ret=0;
	int id;
	char Peliculas[128];
	char Genero[128];
	int Duracion;
	int rubroId;

	if (this!=NULL)
	{
		if(Peliculas_getId(this,&id) && Peliculas_getPeliculas(this,Peliculas) && Peliculas_getGenero(this,Genero) && Peliculas_getDuracion(this,&Duracion))
		{
			if(rubroId==1)
			{
				printf("ID: %d	||| Peliculas: %s  ||| Genero: %s ||| Duracion: $%d ||| RUBRO :Cuidado de Ropa \n",
				id,Peliculas,Genero,Duracion);
			}else if(rubroId == 2)
			{
				printf("ID: %d	||| Peliculas: %s  ||| Genero: %s ||| Duracion: $%d ||| RUBRO :Limpieza y desinfeccion \n",
								id,Peliculas,Genero,Duracion);
			}else if (rubroId==3)
			{
				printf("ID: %d	||| Peliculas: %s  ||| Genero: %s ||| Duracion: $%d ||| RUBRO :Cuidado personal e higiene \n",
				id,Peliculas,Genero,Duracion);
			}else{
				printf("ID: %d	||| Peliculas: %s  ||| Genero: %s ||| Duracion: $%d ||| RUBRO :Cuidado del automotor \n",
								id,Peliculas,Genero,Duracion);
			}


			ret=1;
		}
	}
	return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

int Peliculas_compararPorNombre(void* this1, void* this2)
{
    char auxNombreA[4096];
    char auxNombreB[4096];

    Peliculas_getPeliculas((ePeliculas*)this1, auxNombreA);
    Peliculas_getPeliculas((ePeliculas*)this2, auxNombreB);

    if(strcmp(auxNombreA, auxNombreB) > 0)
    {
        return 1;
    }
    if(strcmp(auxNombreA, auxNombreB) < 0)
    {
        return -1;
    }
    return 0;
}
