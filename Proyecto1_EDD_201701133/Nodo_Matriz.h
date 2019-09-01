#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <Nodo_Color.h>

class Nodo_Matriz
{
    public:
        //para cada nodo de color
        Nodo_Color *inicio;

        //para la lista de matrices
        int Z;
        std::string NombreDocumento;
        Nodo_Matriz *siguiente;
        Nodo_Matriz *anterior;



        Nodo_Matriz(int z,std::string NombreDoc);

        int BuscarX(int x);
        int BuscarY(int y);
        CrearColumnaX(int x);
        CrearFilaY(int y);
        InsertarX(Nodo_Color* nuevo);
        InsertarY(Nodo_Color* nuevo);
        InsertarCodigo(int x,int y,std::string color);
        CargaColores(char ruta[]);

        mostrartodo();
        mostrartodoy();






        virtual ~Nodo_Matriz();

    protected:

    private:
};

#endif // NODO_MATRIZ_H
