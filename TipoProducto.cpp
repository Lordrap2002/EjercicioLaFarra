#include <iostream>
#include "TipoProducto.h"

TipoProducto::TipoProducto(){
    this->nombre = "NA";
    this->iva = 0;
}

TipoProducto::TipoProducto(string nombre, float iva){
    this->nombre = nombre;
    this->iva = iva;
}

string TipoProducto::getNombre(){
    return this->nombre;
}

void TipoProducto::setNombre(string nombre){
    this->nombre = nombre;
}

float TipoProducto::getIva(){
    return this->iva;
}

void TipoProducto::setIva(float iva){
    this->iva = iva;
}