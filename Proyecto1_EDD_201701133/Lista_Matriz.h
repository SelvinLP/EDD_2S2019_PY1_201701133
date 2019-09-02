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
        Nodo_Matriz *inicio;
        Nodo_Matriz *fin;
        Lista_Matriz();

        InsertarMatrizOrdenado(int z,char NombreDoc[]);


        virtual ~Lista_Matriz();

    protected:

    private:
};

#endif // LISTA_MATRIZ_H
