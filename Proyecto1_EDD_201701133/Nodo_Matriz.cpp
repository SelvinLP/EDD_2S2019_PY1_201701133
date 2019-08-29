#include "Nodo_Matriz.h"
#include <string>
#include <stdio.h>
Nodo_Matriz::Nodo_Matriz(int z,std::string NombreDoc){
    inicio=new Nodo_Color(-1,-1,"RAIZ");
    this->siguiente=0;
    this->anterior=0;
    this->Z=z;
    this->NombreDocumento=NombreDoc;
}

Nodo_Matriz::mostrartodo(){
    Nodo_Color* tem=inicio;
    Nodo_Color* tem2=0;
    tem=tem->siguiente;
    while(tem !=0){
        tem2=tem;
        while(tem2!=0){
            printf("Descripcion: %s\n",tem2->Color.c_str());
            printf("Fila %d\n",tem2->Y);
            printf("Columna %d\n",tem2->X);
            tem2=tem2->abajo;
        }
        tem=tem->siguiente;
    }
}
Nodo_Matriz::mostrartodoy(){
    Nodo_Color* tem=inicio;
    Nodo_Color* tem2=0;
    tem=tem->abajo;
    while(tem !=0){
        tem2=tem;
        while(tem2!=0){
            printf("Descripcion: %s\n",tem2->Color.c_str());
            printf("Fila %d\n",tem2->Y);
            printf("Columna %d\n",tem2->X);
            tem2=tem2->siguiente;
        }
        tem=tem->abajo;
    }
}



Nodo_Matriz::BuscarX(int x){
    Nodo_Color* tem=inicio;
    while(tem !=0){
        if(tem->X==x){
            return 1;
        }
        tem=tem->siguiente;
    }
    return 0;
}

Nodo_Matriz::BuscarY(int y){
    Nodo_Color* tem=inicio;
    while(tem !=0){
        if(tem->Y==y){
            return 1;
        }
        tem=tem->abajo;
    }
    return 0;
}

Nodo_Matriz::CrearColumnaX(int x){
    Nodo_Color *RaizColumnaX=inicio;
    Nodo_Color *tem=inicio;
    Nodo_Color *fin=0;
    Nodo_Color *nuevo=new Nodo_Color(x,-1,"COLUMNA");
    bool bandera=false;
    while(RaizColumnaX!=0){
        if(RaizColumnaX->X > x){
            bandera=true;
            tem=RaizColumnaX;
        }
        if(RaizColumnaX->siguiente==0){
            fin=RaizColumnaX;
        }
        RaizColumnaX=RaizColumnaX->siguiente;
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

Nodo_Matriz::CrearFilaY(int y){
    Nodo_Color* RaizFilaY=inicio;
    Nodo_Color* tem=inicio;
    Nodo_Color* fin=0;
    Nodo_Color* nuevo=new Nodo_Color(-1,y,"FILA");
    bool bandera=false;
    while(RaizFilaY!=0){
        if(RaizFilaY->Y > y){
            bandera=true;
            tem=RaizFilaY;
            break;
        }
        if(RaizFilaY->abajo==0){
            fin=RaizFilaY;
        }
        RaizFilaY=RaizFilaY->abajo;
    }
    if(bandera){
        //incertamos valores antes del temporal que es el encontrado
        nuevo->abajo=tem;
        tem->arriba->abajo=nuevo;
        nuevo->arriba=tem->arriba;
        tem->arriba=nuevo;
    }else{
        fin->abajo=nuevo;
        nuevo->arriba=fin;
    }
}

Nodo_Matriz::InsertarX(Nodo_Color* nuevo){
    Nodo_Color* RaizColumnaX=inicio;
    Nodo_Color* tem2=inicio;
    Nodo_Color* fin=0;
    bool bandera=false;
    while(RaizColumnaX !=0){
        if(RaizColumnaX->X==nuevo->X){
            if(RaizColumnaX->Y > nuevo->Y){
                bandera=true;
                tem2=RaizColumnaX;
                break;
            }
            if(RaizColumnaX->abajo==0){
                fin=RaizColumnaX;
            }
            RaizColumnaX=RaizColumnaX->abajo;
        }else{
            RaizColumnaX=RaizColumnaX->siguiente;
        }
    }
    if(bandera){
        nuevo->abajo=tem2;
        tem2->arriba->abajo=nuevo;
        nuevo->arriba=tem2->arriba;
        tem2->arriba=nuevo;
    }else{
        fin->abajo=nuevo;
        nuevo->arriba=fin;
    }

}
Nodo_Matriz::InsertarY(Nodo_Color* nuevo){
    Nodo_Color* RaizFilaY=inicio;
    Nodo_Color* tem=inicio;
    Nodo_Color* fin=0;
    bool bandera=false;
    while(RaizFilaY !=0){
        if(RaizFilaY->Y==nuevo->Y){
            if(RaizFilaY->X > nuevo->X){
                bandera=true;
                tem=RaizFilaY;
                break;
            }
            if(RaizFilaY->siguiente==0){
                fin=RaizFilaY;
            }
            RaizFilaY=RaizFilaY->siguiente;
        }else{
            RaizFilaY=RaizFilaY->abajo;
        }
    }
    if(bandera){
        nuevo->siguiente=tem;
        tem->anterior->siguiente=nuevo;
        nuevo->anterior=tem->anterior;
        tem->anterior=nuevo;
    }else{
        fin->siguiente=nuevo;
        nuevo->anterior=fin;
    }

}

Nodo_Matriz::InsertarCodigo(int x,int y, std::string color){
    Nodo_Color* nuevo=new Nodo_Color(x,y,color);
    int columna=BuscarX(x);
    int fila=BuscarY(y);
    //casos de insercion
    //primer caso columna y fila no existe
    if(columna==0 && fila==0){
        CrearColumnaX(x);
        CrearFilaY(y);
        InsertarX(nuevo);
        InsertarY(nuevo);
    }else{
        if(columna!=0 && fila==0){
            CrearFilaY(y);
            InsertarX(nuevo);
            InsertarY(nuevo);
        }else{
            if(columna==0 && fila!=0){
                CrearColumnaX(x);
                InsertarX(nuevo);
                InsertarY(nuevo);
            }else{
                if(columna!=0 && fila!=0){
                    InsertarX(nuevo);
                    InsertarY(nuevo);
                }
            }
        }
    }
}




Nodo_Matriz::~Nodo_Matriz()
{
    //dtor
}
