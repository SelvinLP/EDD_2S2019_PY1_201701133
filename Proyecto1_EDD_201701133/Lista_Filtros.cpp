#include "Lista_Filtros.h"

Lista_Filtros::Lista_Filtros()
{
    //ctor
}
//mostrar filtros
Lista_Filtros::MostrarFiltros(int iterado,Lista_Matriz *Cubo,int posz){
    if(iterado==-1){
        int pos=1;
        Nodo_Filtro *tem=inicio;
        if(tamao==1){
            printf("  %d",pos);
            printf(".");
            printf(" Filtro:  %s",tem->Actividad.c_str());
            if(tem->Z==-1){
                printf("    Capa:  Todas\n");
            }else{
                printf("    Capa:  %d\n",tem->Z);
            }
        }else{
            //primera iteracion
            printf("  %d",pos);
            printf(".");
            printf(" Filtro:  %s",tem->Actividad.c_str());
            if(tem->Z==-1){
                printf("    Capa:  Todas\n");
            }else{
                printf("    Capa:  %d\n",tem->Z);
            }

            tem=tem->siguiente;
            while(tem!=inicio){
                pos+=1;
                printf("  %d",pos);
                printf(".");
                printf(" Filtro:  %s",tem->Actividad.c_str());
                if(tem->Z==-1){
                    printf("    Capa:  Todas\n");
                }else{
                    printf("    Capa:  %d\n",tem->Z);
                }
                tem=tem->siguiente;
            }
        }
    }
    //seleccion de opcion
    if(iterado==0){
        int pos=1;
        Nodo_Filtro *tem=inicio;
        if(tamao==1){
            if(tem->Z==-1){
                MostrarFiltros(1,Cubo,tem->Z);
            }else{
                MostrarFiltros(1,Cubo,tem->Z);
            }
        }else{
            //primera iteracion
            if(posz==pos){
                if(tem->Z==-1){
                    MostrarFiltros(1,Cubo,tem->Z);
                }else{
                    MostrarFiltros(1,Cubo,tem->Z);
                }
            }

            tem=tem->siguiente;
            while(tem!=inicio){
                pos+=1;

                if(posz==pos){
                    if(posz==-1){
                        MostrarFiltros(1,Cubo,tem->Z);
                    }else{
                        MostrarFiltros(1,Cubo,tem->Z);
                    }
                }
                tem=tem->siguiente;
            }
        }
    }
    if(iterado==1){
        if(posz==-1){
            //muestra capas
            Nodo_Matriz *tem2=Cubo->inicio;
            tem2=tem2->siguiente;
            while(tem2!=0){
                printf("Profundidad: %d",tem2->Z);
                printf("    Descripcion: %s\n",tem2->NombreDocumento.c_str());
                tem2=tem2->siguiente;
            }
            //fin
        }else{
            //muestra capas
            Nodo_Matriz *tem2=Cubo->inicio;
            tem2=tem2->siguiente;
            while(tem2!=0){
                if(tem2->Z==posz){
                    printf("Profundidad: %d",tem2->Z);
                    printf("    Descripcion: %s\n",tem2->NombreDocumento.c_str());
                }
                tem2=tem2->siguiente;
            }
        }

    }

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
    //para z
    std::stringstream ssz;
    std::string mz;
    ssz.str(std::string());
    ssz.clear();
    ssz<<tem->Z;
    ssz>>mz;

    if(tamao==1){
        if(tem->Z==-1){
            CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+" Capa:Todas"+"\"]; \n" ;

        }else{
            CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+" Capa:"+mz+"\"]; \n" ;
        }

    }else{
        if(tem->Z==-1){
            CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+" Capa:Todas"+"\"]; \n" ;

        }else{
            CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+" Capa:"+mz+"\"]; \n" ;
        }
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

                //para z
            std::stringstream ssz;
            std::string mz;
            ssz.str(std::string());
            ssz.clear();
            ssz<<tem->Z;
            ssz>>mz;

            if(tem->Z==-1){
                CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+" Capa:Todas"+"\"]; \n" ;

            }else{
                CadenaGRAFICA += "\""+ tem->Actividad+mgh+"\"" +"[label =\" "+tem->Actividad+" Capa:"+mz+"\"]; \n" ;
            }
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

Lista_Filtros::Insertar(std::string dato,int posz){
    Nodo_Filtro* nuevo=new Nodo_Filtro(dato,posz);
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
