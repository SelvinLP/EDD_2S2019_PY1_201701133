#ifndef NODO_COLOR_H
#define NODO_COLOR_H
#include <string>

class Nodo_Color
{
    public:
        int X;//eje x
        int Y;//eje y
        std::string Color;
        Nodo_Color* siguiente;
        Nodo_Color* anterior;
        Nodo_Color* arriba;
        Nodo_Color* abajo;

        Nodo_Color(int x,int y,std::string color);
        virtual ~Nodo_Color();

    protected:

    private:
};

#endif // NODO_COLOR_H
