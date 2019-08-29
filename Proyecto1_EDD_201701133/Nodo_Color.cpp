#include "Nodo_Color.h"

Nodo_Color::Nodo_Color(int x,int y,std::string color)
{
    this->X=x;
    this->Y=y;
    this->Color=color;
    this->siguiente=0;
    this->anterior=0;
    this->abajo=0;
    this->arriba=0;
}

Nodo_Color::~Nodo_Color()
{
    //dtor
}
