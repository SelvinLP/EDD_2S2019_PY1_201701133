#ifndef ARBOL_H
#define ARBOL_H
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

#include<Lista_Matrices.h>

class Arbol
{
    public:
        Arbol();

        CargaTotal(char ruta[]);
        virtual ~Arbol();

    protected:

    private:
};

#endif // ARBOL_H
