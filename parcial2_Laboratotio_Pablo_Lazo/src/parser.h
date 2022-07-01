
/**\brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListPeliculas LinkedList* puntero a array de empleados.
 * \return int ret -1 si el puntero pFile es NULL o el puntero pArrayListPeliculas es NULL,
                   0 si logro parsear con exito.
 */
int parser_PeliculasFromText(FILE* pFile , LinkedList* pArrayListPeliculas);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *  \param pFile FILE* puntero a archivo.
 *  \param pArrayListPeliculas LinkedList* puntero a array de empleados.
 *  \return int ret -1 cuando pFile es NULL o pArrayListPeliculas es NULL,
                    0 cuando logro parsear cone exito.
 */
int parser_PeliculasFromBinary(FILE* pFile , LinkedList* pArrayListPeliculas);
