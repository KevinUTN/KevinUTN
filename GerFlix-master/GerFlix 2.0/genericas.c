#include "Usuario.h"
#include "Serie.h"
#include <string.h>
#include <stdio.h>


void menu(char *opciones)
{
    system("cls");
    printf("%s \n",opciones);
    printf("\n0.  Salir \n");
    printf("\n\tIngrese Opcion: ");
}

void mostrarUsuariosXSeries(eSerie series[], int cantSeries,eUsuario usuarios[], int cantUsuarios)
{
    int flag=-1;
    for(int i=0;i<cantUsuarios;i++)
    {
        if(usuarios[i].estado==1)
        {//usuario activo
            printf("\nEl Usuario: %s",usuarios[i].nombre);
            printf("\n Ve las siguientes series: \n");

            for(int j=0;j<cantSeries;j++)
            {// buscar el id de la serie

                if((series[j].idSerie==usuarios[i].idSerie)&&(series[j].estado==1))
                {//serie Habilitada && usuario ver la serie
                    mostrarSerie(series[j]);
                    flag=1;//encontro y esta habilitada
                }//if((series[j].idSerie==usuarios[i].idSerie)&&(series[j].estado==1))

            }//for(int j=0;j<cantSeries;j++)
            if(flag==-1)
            {//no encontro la serie o se dio de baja
                printf("\n Serie Inexistente o dada de baja...\n");
            }
            flag=-1;
            printf("---------------\n");
        }//if(usuarios[i].estado==1)
    }//for(int i=0;i<cantUsuarios;i++)
    system("pause");
}

void mostrarSeriesXUsuarios(eSerie series[], int cantSeries,eUsuario usuarios[], int cantUsuarios)
{
    int flag=-1;
    for(int j=0;j<cantSeries;j++)
    {// buscar el id de la serie
        if(series[j].estado==1)
        {//Serie Habilitada
            printf("\nLa serie: %s",series[j].nombre);
            printf("\n La ven los siguientes usuarios: \n");
            for(int i=0;i<cantUsuarios;i++)
            {//recorro los usuarios para buscar si ve la serie
                if((series[j].idSerie==usuarios[i].idSerie)&&(usuarios[i].estado==1))
                {//Usuario Habilitado && ve la serie.
                    mostrarUsuario(usuarios[i]);
                    flag=1;// la ve almenos 1 usuario
                }

            }//for(int i=0;i<cantUsuarios;i++)
            if(flag==-1)
            {//la serie no la ve nadie
                printf("\n Nadie ve esta Serie...\n");
            }
            flag=-1;
            printf("\n---------------\n");
        }//if(series[j].estado==1)
    }//for(int j=0;j<cantSeries;j++)
    system("pause");
}
/*
char *get_char(char *sms,int LongitudCadena)
{
    char *PTexto= (char *) malloc (sizeof(char)*LongitudCadena);
    char *TextoLibre= (char *) malloc (sizeof(char)*LongitudCadena+2);
    fflush(stdin);
    int flag=0;
    do
    {
        printf("%s ",sms);
        fgets(TextoLibre,LongitudCadena+2,stdin);
        if(flag==1)
        {
            printf("\n La longitud maxima del campo es: %d \n",LongitudCadena);
            system("pause");
            system("cls");
        }
        flag=1;
    }while(strlen(TextoLibre) >= LongitudCadena);

    strcpy(PTexto,TextoLibre);
    return PTexto;
}
*/
void Alta_Usuarios(eSerie series[], int cantSeries,eUsuario usuarios[], int cantUsuarios)
{
    int posicionDeIngreso;
    int nuevoId;
    int serieExistente;
    posicionDeIngreso = buscarPosicionLibreUsuarios(usuarios, cantUsuarios);
    if(posicionDeIngreso==-1)
    {
        printf("\n LLego al maximo de usuarios no se puede agregar mas...");
    }
    else
    {
        nuevoId = getNewId(usuarios, cantUsuarios);
        usuarios[posicionDeIngreso] = getNewUser(nuevoId);
        do
        {
                mostrarListaSeries(series, cantSeries);
                printf("\nIngrese ID de la serie que ve el Usuario: ");
                scanf("%d", &usuarios[posicionDeIngreso].idSerie);
                serieExistente = existeSerie(series, usuarios[posicionDeIngreso].idSerie, cantSeries);
                if(serieExistente == 0)
                {
                    printf("\nEl ID ingresado no existe. Por favor vuelva a ingresar el dato");
                }
            } while(serieExistente == 0);
    }//if(posicionDeIngreso==-1)

}

int getNewId(eUsuario lista[], int cant)
{
    int nuevoId;
    int maximo;
    int Flag=0;
    for(int i = 0; i < cant; i++)
    {
        if(lista[i].estado != 0)
        {
            if(lista[i].idUsuario > maximo || Flag == 0)
            {
                maximo = lista[i].idUsuario;
                Flag=1;
            }
        }
    }

    if(Flag == 1)
    {
        nuevoId = maximo + 1;
    }
    else
    {
        nuevoId = 1;
    }

    return nuevoId;
}
