#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H
#include <string>
#include <Nodo_Color.h>

class Nodo_Matriz
{
    public:
        Nodo_Color *inicio;
        Nodo_Matriz();

        int BuscarX(int x);
        int BuscarY(int y);
        CrearColumnaX(int x);
        CrearFilaY(int y);
        InsertarX(Nodo_Color* nuevo);
        InsertarY(Nodo_Color* nuevo);
        InsertarCodigo(int x,int y,std::string color);

        mostrartodo();
        mostrartodoy();






        virtual ~Nodo_Matriz();

    protected:

    private:
};

#endif // NODO_MATRIZ_H
