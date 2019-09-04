#include "Arbol.h"

Arbol::Arbol()
{
    this->Raiz=0;
}
//empiza metodos para raficar
Arbol::GraficaInorden(){
    std::ofstream file;
    file.open("GraficaArbolINORDEN.dot");
    Lista_Matriz* tem=Raiz;
    Lista_Matriz* tem2=0;

    std::string CadenaImprimir= "digraph GraficaINORDEN { \n";
    CadenaImprimir += "size=\"9,9\" \n";
    CadenaImprimir += "rankdir=LR \n" ;
    CadenaImprimir += "node[shape=circle,style=filled] \n" ;
    //creacion de nodos


    CadenaImprimir+="}";
    file<<CadenaImprimir;
    file.close();
    system("dot -Tpng GraficaArbolINORDEN.dot -o  GraficaArbolINORDEN.png");
    system("Start GraficaArbolINORDEN.png");
}


//termina metodos para graficar
Arbol::MostrarInorden(Lista_Matriz* lt){
    if(lt==0){
        //no imprime nada
    }else{
        MostrarInorden(lt->izquierda);
        printf("Img: %s\n",lt->NombreCubo.c_str());
        MostrarInorden(lt->derecha);
    }
}
Arbol::InsertarCubo(char ruta[]){
    Lista_Matriz *nuevo=new Lista_Matriz(ruta);
    Lista_Matriz *tem=Raiz;
    if(Raiz==0){
        Raiz=nuevo;
    }else{
        while(tem!=0){
            if(tem->NombreCubo.compare(ruta)>0){
                //inserta lado izquierdo
                if(tem->izquierda==0){
                    tem->izquierda=nuevo;
                    break;
                }

                tem=tem->izquierda;
            }else{
                //inserta lado derecho
                if(tem->derecha==0){
                    tem->derecha=nuevo;
                    break;
                }
                tem=tem->derecha;
            }
        }

    }
}
Arbol::CargaTotal(char ruta[]){
    Lista_Matriz *Lista_M=new Lista_Matriz(ruta);
    int capa=-1;
    char archivoCapa[150];
    int primeralinea=0;


    std::fstream archivo(ruta);
    if(archivo.fail()){
       printf("El archivo T no se logro abrir \n");
    }else{
        for (std::string linea; std::getline(archivo, linea); )
        {
            std::stringstream registro(linea);
            for (std::string dato; std::getline(registro, dato, ';'); )
            {

                if(primeralinea==0){
                    //no toma en cuenta la primera linea
                }else{
                    if(capa==-1){
                        capa=atoi(dato.c_str());
                    }
                    else{
                        dato.copy(archivoCapa, dato.size() + 1);
                        archivoCapa[dato.size()] = '\0';
                    }
                }

            }
            //iteracion para que no tome en cuenta la primera linea
            primeralinea+=1;
            //if para ver si es el archivo de configuracion o no
            if(capa==0||capa==-1){
                //archivo de configuracion
            }else{

                Lista_M->InsertarMatrizOrdenado(capa,archivoCapa);
            }
            //reinicia el contador de capa
            capa=-1;

        }
    }
    //temporal
    //Lista_M->MostrarLista(5);

}

Arbol::~Arbol()
{
    //dtor
}
