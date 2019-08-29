#include "Lista_Matrices.h"

Lista_Matrices::Lista_Matrices()
{
    inicio=0;
    fin=0;
}

Lista_Matrices::InsertarMatrizOrdenado(int z,std::string NombreDoc){
    Nodo_Matriz *nuevo=new Nodo_Matriz(z,NombreDoc);
    Nodo_Matriz *tem=inicio;
    Nodo_Matriz *tem2=inicio;
    bool bandera=false;
    if(inicio==0){
        inicio=nuevo;
        fin=nuevo;
    }else{
        while(tem2!=0){
            if(tem2->Z > z){
                bandera=true;
                tem=tem2;
            }
            tem2=tem2->siguiente;
        }
        if(bandera){
        //incertamos valores antes del temporal que es el encontrado
            nuevo->siguiente=tem;
            tem->anterior->siguiente=nuevo;
            nuevo->anterior=tem->anterior;
            tem->anterior=nuevo;
        }else{
            fin->siguiente=nuevo;
            nuevo->anterior=fin;
        }

    }
}




Lista_Matrices::~Lista_Matrices()
{
    //dtor
}
