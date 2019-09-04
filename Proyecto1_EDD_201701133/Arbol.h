#ifndef ARBOL_H
#define ARBOL_H
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

#include <Lista_Matriz.h>
class Arbol
{
    public:
        //raiz del arbol
        Lista_Matriz* Raiz;
        Arbol();

        MostrarInorden(Lista_Matriz* lt);

        GraficaInorden();
        GraficaPsorden();
        GraficaProrden();

        InsertarCubo(char ruta[]);
        CargaTotal(char ruta[]);

        virtual ~Arbol();

    protected:

    private:
};

#endif // ARBOL_H
