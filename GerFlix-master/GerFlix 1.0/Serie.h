
typedef struct
{
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;
}eSerie;

void inicializarSeriesEstado(eSerie[], int);
void inicializarSeriesHardCode(eSerie[]);

/** \brief mostrarListaSeries
 *
 * Recorre todas las series Habilitadas y llama a la funcion que imprime sus datos
 *
 * \param eSerie[]
 * \param int
 * \return void
 *
 */
void mostrarListaSeries(eSerie[], int);

/** \brief mostrarSerie
 *
 * Imprime los datos de un registro de serie
 *
 * \param serie eSerie
 * \return void
 *
 */
void mostrarSerie(eSerie serie);
