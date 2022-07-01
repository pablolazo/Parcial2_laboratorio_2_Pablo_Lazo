/*
 ============================================================================
 Name        : parcial2_Laboratotio_Pablo_Lazo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"

#include "controller.h"


int main(void) {
	setbuf(stdout,NULL);

	LinkedList* listarPeliculas = ll_newLinkedList();

	 char seguir='s';
	    int opcion;
	    int flag = 0;
	    char Genero[300];
	    int Duracion;


	    while (seguir=='s')
	    {
	       printf("\n------MENU------"
		        	   "\n1- Cargar los datos en un archivo ingresado(modo texto)."
	        		   "\n2- Listar "
	        		   "\n3- Mappeado por tiempo"
	    		       "\n4- Filtrar por Tipo "
	    		       "\n5- Informes por duracion"
		        	   "\n6- Generar el archivo de salida: mapeado.csv"

		        	   "\n7-SALIR\n");
	        scanf("%d", &opcion);
	        switch (opcion)
	        				{
	        				case 1:
	        					controller_loadFromText("movies.csv",listarPeliculas);
	        				   controller_saveAsText(Genero,listarPeliculas);

	        					printf("\nDatos guardados exitosamente");
	        				break;
	        				case 2:
	        					controller_ListPeliculas(listarPeliculas);
			                break;
	        				case 3:
	        					controller_saveMappeado(listarPeliculas);
	        					 printf("\nSe mappeo con exito");

	        			    break;
	        			    case 4:
	        			    controller_sortPeliculas(listarPeliculas);
	        			    controller_saveAsText(Genero,listarPeliculas);
	        			    printf("\nOrdneado con exito");
	        			    break;
	        			    case 5:
	        			    controller_sortPeliculas(listarPeliculas);
	        			    controller_saveAsText(Duracion,listarPeliculas);
	        			    printf("\nOrdneado con exito");
	        			     break;



	        				case 6:
	        					controller_saveAsText("movies.csv", listarPeliculas);
	        					printf("Hasta Pronto");
	        					seguir = 'n';
	        					break;
	    }}


	    return 0;
}
