#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"





int parser_PeliculasFromText(FILE* pFile , LinkedList* pArrayListPeliculas)
{
	int ret;
	char buffer[4][200];

	ePeliculas *pPeliculas;

	if(pFile!=NULL && pArrayListPeliculas!=NULL)
	{
		fscanf(pFile,"[^\n]\n");
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		    printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]); //Para ver lo que va cargando

			pPeliculas = Peliculas_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

			if(pPeliculas != NULL)
			{
				if(!ll_add(pArrayListPeliculas,pPeliculas))
				{
					ret = 0;
				}
			}
		}
	}
	fclose(pFile);
	return ret;
}

int parser_PeliculasFromBinary(FILE* pFile, LinkedList* pArrayListPeliculas)
{
    int ret = -1;
    ePeliculas auxPeliculas;
    ePeliculas* pPeliculas= NULL;

    if(pFile != NULL && pArrayListPeliculas != NULL)
    {
        while(!feof(pFile))
        {
            pPeliculas = Peliculas_new();
            fread(&auxPeliculas, sizeof(ePeliculas), 1, pFile);


                fread(&auxPeliculas, sizeof(ePeliculas), 1, pFile);
                if(pPeliculas!= NULL)
                {
                    ll_add(pArrayListPeliculas, pPeliculas);
                    ret = 0;
                }


            else
            {
                Peliculas_delete(pPeliculas);
            }

        }
        fclose(pFile);
        free(pArrayListPeliculas);
    }
    return ret;
}



