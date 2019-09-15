#ifndef ARBOL_H
#define ARBOL_H
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include<bits/stdc++.h>

#include <Lista_Matriz.h>
#include<Nodo_Matriz.h>
class Arbol
{
    public:
        //raiz del arbol
        Lista_Matriz* Raiz;
        Arbol();
        //busca y modifica
        BuscayModifica(int posz,std::string dato, Lista_Matriz*lt,int dx,int dy,int dr,int dg,int db);
        //copiar seleccion de imagen
        Lista_Matriz* BuscarSeleccion(std::string dato, Lista_Matriz*lt,Lista_Matriz*rt);

        MostrarInorden(Lista_Matriz* lt);
        BuscarArbol(int posz,std::string dato, Lista_Matriz*lt);

        //para la linealizacion
        BuscarArbolLineal(int filaycolumna,int posz,std::string dato,Lista_Matriz*lt);

        std::string CadenaGRAFICA;
        std::vector <std::string> Nomb;
        GraficaInorden();
        DatosGraficaI(Lista_Matriz* lt);
        GraficaPsorden();
        DatosGraficaPOS(Lista_Matriz* lt);
        GraficaProrden();
        DatosGraficaPRE(Lista_Matriz* lt);

        //graficar arbol completo
        GraficarARBOL();
        DatosGraficaARBOL(Lista_Matriz* lt);


        InsertarCubo(char Nombre[],char ruta[]);
        CargaTotal(Lista_Matriz* nuevo,char rutaA[],char ruta[]);

        virtual ~Arbol();

    protected:

    private:
};

#endif // ARBOL_H
