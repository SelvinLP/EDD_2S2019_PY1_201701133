#include "Arbol.h"

Arbol::Arbol()
{
    this->Raiz=0;
}
Arbol::valor(char ruta[]){
    std::string abc[27]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","ñ","o","p","q","r","s","t","u","v","w","x","y","z"};
    std::string abc2[27]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","Ñ","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int pos=0;
    while(pos!=27){
        //printf("Numero: %s\n",abc[pos].c_str());
        if(abc[pos]==ruta){
            return pos;
            break;
        }else{
            if(abc2[pos]==ruta){
                return pos;
                break;
            }
        }
        pos+=1;
    }
    return -1;
}
Arbol::InsertarCubo(char ruta[]){
    Lista_Matriz* Inicio=Raiz;
    Lista_Matriz *Lista_M=new Lista_Matriz(ruta);
    int posicion=0;
    if(Inicio==0){
        Raiz=Lista_M;
    }else{
       // while(Inicio!=0){
         //   char s[1]=Inicio->NombreCubo;
           // int Padre=valor(Inicio->NombreCubo.front());
           // if(){

          //  }
        //}
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
