#include "Arbol.h"

Arbol::Arbol()
{

}
Arbol::CargaTotal(char ruta[]){
    Lista_Matrices *Lista_M=new Lista_Matrices();
    int capa=-1;
    std::string archivoCapa;
    int primeralinea=0;


    std::fstream archivo(ruta);
    if(archivo.fail()){
       printf("El archivo no se logro abrir \n");
    }else{
        printf("El archivo se abrio Correctamente \n");
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
                        archivoCapa=dato.c_str();
                    }
                }

            }
            //iteracion para que no tome en cuenta la primera linea
            primeralinea+=1;
            //if para ver si es el archivo de configuracion o no
            if(capa==0){
                //archivo de configuracion
            }else{
                Lista_M->InsertarMatrizOrdenado(capa,archivoCapa);
            }
            //reinicia el contador de capa
            capa=-1;

        }
    }
}
Arbol::~Arbol()
{
    //dtor
}
