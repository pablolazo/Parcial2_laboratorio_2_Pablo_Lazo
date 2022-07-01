
#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_ListPeliculas(LinkedList* pArrayList);
int controller_saveAsText(char* path, LinkedList* pArrayList);
void nombreArchivoPorParametro(LinkedList* pArrayList);
int controller_sortPeliculass(LinkedList* pArrayListEmployee);


void mapeadoPeliculass(void* this);
int controller_saveMappeado(LinkedList* pArrayList);

int Peliculass_ (void* this);
int Peliculass_Mayores100 (void* this);
int controller_informes( LinkedList* pArrayList);

#endif /* CONTROLLER_H_ */


