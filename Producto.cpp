#include <iostream>
#include "Producto.h"

Producto::Producto(){
    this->nombre = "NA";
    this->costo = this->precio = 0;
    this->cantUnidades = this->codigo = 0;
}

Producto::Producto(TipoProducto tipoProducto, string nombre, float precio, float costo, int codigo, int cantUnidades){
    this->nombre = nombre;
    this->tipoProducto = tipoProducto;
    this->codigo = codigo;
    this->costo = costo;
    this->precio = precio;
    this->cantUnidades = cantUnidades;
}

void Producto::mostrarProducto(){
    cout << "Nombre: " << nombre << ".\n"
        << "Codigo: " << codigo << ".\n"
        << "Precio: " << precio << ".\n"
        << "IVA: " << tipoProducto.getIva() << "%.\n"
        << "Cantidad de unidades: " << cantUnidades << ".\n"
        << "Tipo de producto: " << tipoProducto.getNombre() << ".\n";
}

string Producto::getNombre(){
    return this->nombre;
}

void Producto::setNombre(string nombre){
    this->nombre = nombre;
}

float Producto::getPrecio(){
    return this->precio;
}

void Producto::setPrecio(float precio){
    this->precio = precio;
}

int Producto::getCodigo(){
    return this->codigo;
}

void Producto::setCodigo(int codigo){
    this->codigo = codigo;
}

float Producto::getCosto(){
    return this->costo; 
}

void Producto::setCosto(float costo){
    this->costo = costo;
}

int Producto::getCantUnidades(){
    return this->cantUnidades; 
}

void Producto::setCantUnidades(int cantUnidades){
    this->cantUnidades = cantUnidades;
}

TipoProducto Producto::getTipoProducto(){
    return this->tipoProducto;
}

void Producto::setTipoProducto(TipoProducto tipoProducto){
    this->tipoProducto = tipoProducto;
}
