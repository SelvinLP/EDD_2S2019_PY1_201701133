#ifndef LISTA_MATRICES_H
#define LISTA_MATRICES_H
#include <string>
#include <Nodo_Matriz.h>

class Lista_Matrices
{
    public:
        Nodo_Matriz *inicio;
        Nodo_Matriz *fin;
        Lista_Matrices();

        InsertarMatrizOrdenado(int z,std::string NombreDoc);
        MostrarlistadeNodos();

        virtual ~Lista_Matrices();

    protected:

    private:
};

#endif // LISTA_MATRICES_H
