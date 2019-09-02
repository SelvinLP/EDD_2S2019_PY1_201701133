#include "Lista_Matriz.h"

Lista_Matriz::Lista_Matriz()
{
    this->fin=0;
    this->inicio=0;
}


Lista_Matriz::InsertarMatrizOrdenado(int z,char NombreDoc []){
    std::string cad="";
    Nodo_Matriz *nuevo=new Nodo_Matriz(z,NombreDoc);
    nuevo->CargarColor(NombreDoc);

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
                break;
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




Lista_Matriz::~Lista_Matriz()
{
    //dtor
}
