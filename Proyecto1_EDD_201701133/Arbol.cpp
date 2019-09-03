#include "Arbol.h"

Arbol::Arbol()
{
    //ctor
}
Arbol::CargaTotal(char ruta[]){
    Lista_Matriz *Lista_M=new Lista_Matriz();
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
