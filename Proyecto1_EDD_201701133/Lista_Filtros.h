#ifndef LISTA_FILTROS_H
#define LISTA_FILTROS_H
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include<bits/stdc++.h>

#include<Lista_Matriz.h>



class Nodo_Filtro {
    public:
        //Lista Doble de filtros
        std::string Actividad;
        int Z;
        Nodo_Filtro* siguiente;
        Nodo_Filtro* anterior;
        Nodo_Filtro(std::string act,int poz):Actividad(act),Z(poz),siguiente(0),anterior(0) {}
};
class Lista_Filtros
{
    public:
        Lista_Filtros();
        Nodo_Filtro* inicio=0;
        Nodo_Filtro* fin=0;
        int tamao=0;


        Insertar (std::string  dato,int posz);
        MostrarFiltros(int iterado,Lista_Matriz *Cubo,int posz);
        GraficarFiltro();
        std::string CadenaGRAFICA;




        virtual ~Lista_Filtros();

    protected:

    private:
};

#endif // LISTA_FILTROS_H
