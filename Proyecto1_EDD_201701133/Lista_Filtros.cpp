#include "Lista_Filtros.h"

Lista_Filtros::Lista_Filtros()
{
    //ctor
}
Lista_Filtros::GraficarFiltro(){
    int sizes=0;
    std::stringstream ss;
    std::string mgh;
    ss.str(std::string());
    ss.clear();
    ss<<sizes;
    ss>>mgh;
    //pasa los siguientes
    std::stringstream sst;
    std::string mg;
    sst.str(std::string());
    sst.clear();
    sst<<sizes+1;
    sst>>mg;

    std::ofstream file;
    file.open("GraficaFILTRO.dot");
    Nodo_Filtro* tem=inicio;
    //datos de grafica
    CadenaGRAFICA = "digraph GraficaFILTRO { \n";
    CadenaGRAFICA += "size=\"9,9\" \n";
    CadenaGRAFICA += "rankdir=LR \n" ;
    CadenaGRAFICA += "node[shape=record,style=filled]\n" ;
    //creacion de nodos
    if(tamao==1){
        CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+"\"]; \n" ;
    }else{
        CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+"\"]; \n" ;
        //primer enlace
        CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"->"+"\""+tem->siguiente->Actividad+mg+"\"; \n" ;
        CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"->"+"\""+tem->siguiente->Actividad+mg+"\" [dir=back]; \n" ;

        tem=tem->siguiente;
        while(tem!=inicio){
            sizes+=1;


            std::stringstream ss;
            std::string mgh;
            ss.str(std::string());
            ss.clear();
            ss<<sizes;
            ss>>mgh;
            //pasa los siguientes
            std::stringstream sst;
            std::string mg;
            sst.str(std::string());
            sst.clear();
            sst<<sizes+1;
            sst>>mg;

            CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+"\"]; \n" ;
            //creacion de enlaces
            if(tem->siguiente==0){

            }else{
                if(tem->siguiente==inicio){
                    CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"->"+"\""+tem->siguiente->Actividad+"0\"; \n" ;
                    CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"->"+"\""+tem->siguiente->Actividad+"0\" [dir=back]; \n" ;
                }else{
                    CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"->"+"\""+tem->siguiente->Actividad+mg+"\"; \n" ;
                    CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"->"+"\""+tem->siguiente->Actividad+mg+"\"[dir=back]; \n" ;
                }
            }
            tem=tem->siguiente;
        }
    }



    CadenaGRAFICA+="}";
    file<<CadenaGRAFICA;
    file.close();
    system("dot -Tpng GraficaFILTRO.dot -o  GraficaFILTRO.png");
    system("Start GraficaFILTRO.png");
}

Lista_Filtros::Insertar(std::string dato){
    Nodo_Filtro* nuevo=new Nodo_Filtro(dato);
    Nodo_Filtro* aux;
    if(inicio==0){
        inicio=nuevo;
        fin=nuevo;
        tamao=1;
    }else{
        aux = fin;
        fin = nuevo;
        aux->siguiente = nuevo;
        fin->anterior=aux;
        fin->siguiente=inicio;
        inicio->anterior=fin;
        tamao+=1;
    }

}
Lista_Filtros::~Lista_Filtros()
{
    //dtor
}
