#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

class Nodo_Color{
    public:
        int X;//eje x
        int Y;//eje y
        std::string Color;
        Nodo_Color* siguiente;
        Nodo_Color* anterior;
        Nodo_Color* arriba;
        Nodo_Color* abajo;
        Nodo_Color(int x, int y, std::string color): Color(color),Y(y),X(x),siguiente(0),anterior(0),arriba(0),abajo(0){}
};
class Nodo_Matriz
{
    public:
        //para el cubo
        int Z;
        std::string NombreDocumento;
        Nodo_Matriz *siguiente;
        Nodo_Matriz *anterior;
        //datos de Nodo
        Nodo_Color* inicio;
        Nodo_Matriz(int z,std::string NombreDoc);

        MostrarTodo();
        CargarColor(char ruta[]);
        GraficarMatriz();

        int BuscarY (int valory);
        int BuscarX (int valorx);
        CrearFilaY (int valory);
        CrearColumnaX (int valorx);
        InsertarenX(Nodo_Color* nuevo);
        InsertarenY(Nodo_Color* nuevo);

        InsertarColor(int y,int x, std::string color);

        virtual ~Nodo_Matriz();

    protected:

    private:
};

#endif // NODO_MATRIZ_H
