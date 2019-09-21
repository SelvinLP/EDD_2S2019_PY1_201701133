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
        int R;
        int G;
        int B;
        Nodo_Color* siguiente;
        Nodo_Color* anterior;
        Nodo_Color* arriba;
        Nodo_Color* abajo;
        Nodo_Color(int x, int y, std::string color,int r,int g,int b): Color(color),Y(y),X(x),R(r),G(g),B(b),siguiente(0),anterior(0),arriba(0),abajo(0){}
};
class Nodo_Matriz
{
    public:
        //seleccion de cubo o imagen

        CopiarMatriz(Nodo_Matriz *lt);
        //para el cubo
        int Z;
        std::string NombreDocumento;
        Nodo_Matriz *siguiente;
        Nodo_Matriz *anterior;
        //datos de Nodo
        Nodo_Color* inicio;
        Nodo_Matriz(int z,std::string NombreDoc);

        //para graficar
        MostrarTodo();
        CargarColor(char ruta[]);
        GraficarMatriz();

        //Linealizacion de la Matriz
        GraficaLinealFila();
        GraficaLinealColumna();
        //metodos de insecion
        int BuscarY (int valory);
        int BuscarX (int valorx);
        CrearFilaY (int valory);
        CrearColumnaX (int valorx);
        InsertarenX(Nodo_Color* nuevo);
        InsertarenY(Nodo_Color* nuevo);

        InsertarColor(int y,int x, std::string color,int r,int g,int b);

        //cambio de colores
        Negativo();
        EscalaGris();
        //metodos de deplazamiento de nodos
        Xmirror(Nodo_Matriz *lt,int maxx);
        Ymirror(Nodo_Matriz *lt,int maxy);


        virtual ~Nodo_Matriz();

    protected:

    private:
};

#endif // NODO_MATRIZ_H
