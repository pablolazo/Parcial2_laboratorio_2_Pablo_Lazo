/*
 * Peliculas.h
 *
 *  Created on: 1 jul. 2022
 *      Author: USUARIO
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_

#ifndef Peliculas_H_
#define Peliculas_H_

typedef struct
{
    int id;
    char Peliculas[300];
    char Genero[300];
    int Duracion;


}ePeliculas;

ePeliculas* Peliculas_new();
ePeliculas* Peliculas_newParametros(char* idStr,char* Peliculas,char* Genero, char* Duracion);
int Peliculas_delete(ePeliculas* this);

int Peliculas_setId(ePeliculas* this,int id);
int Peliculas_getId(ePeliculas* this,int* id);

int Peliculas_setPeliculas(ePeliculas* this,char* Peliculas);
int Peliculas_getPeliculas(ePeliculas* this,char* Peliculas);

int Peliculas_setGenero(ePeliculas* this,char* Genero);
int Peliculas_getGenero(ePeliculas* this,char* Genero);

int Peliculas_setDuracion(ePeliculas* this,int Duracion);
int Peliculas_getDuracion(ePeliculas* this,int* Duracion);



int Peliculas_Print(ePeliculas* this);
int Peliculas_PrintConString(ePeliculas* this);

int Peliculas_compararPorNombre(void* this1, void* this2);

#endif /* Peliculas_H_ */

#endif /* PELICULAS_H_ */
