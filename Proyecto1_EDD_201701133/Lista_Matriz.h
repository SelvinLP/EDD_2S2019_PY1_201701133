#ifndef LISTA_MATRIZ_H
#define LISTA_MATRIZ_H

#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <Nodo_Matriz.h>

class Lista_Matriz
{
    public:
        //apuntadores para arbol
        std::string NombreCubo;
        int image_width;
        int image_height;
        int pixel_width;
        int pixel_height;

        Lista_Matriz* izquierda;
        Lista_Matriz* derecha;
        //apuntadores de la lista
        Nodo_Matriz *inicio;
        Lista_Matriz(char nombreC[]);

        MostrarLista(int posz);
        MostrarListaLineal(int filaycolumna,int posz);

        InsertarMatrizOrdenado(int z,char NombreDoc[]);
        InsertarConfiguracion(char NombreConfig[]);


        virtual ~Lista_Matriz();

    protected:

    private:
};

#endif // LISTA_MATRIZ_H
