#include "DetalleFactura.h"
#include <iostream>
#include <cstdio>


DetalleFactura::DetalleFactura(){
    this->cantUnidVend = 0;
    this->valorSinIVA = this->valorDelIVA = this->valorTotal = 0;
}

DetalleFactura::DetalleFactura(Producto producto, int cantUnidVend, float valorSinIVA, float valorDelIVA, float valorTotal){
    this->producto = producto;
    this->cantUnidVend = cantUnidVend;
    this->valorSinIVA = valorSinIVA;
    this->valorDelIVA = valorDelIVA;
    this->valorTotal = valorTotal;
}

void DetalleFactura::mostrarDetalle(){
    //cout << std::set();
    printf("%-19s %10d %13f %13f %11f\n", this->producto.getNombre(), this->cantUnidVend, this->valorSinIVA, this->valorDelIVA, this->valorTotal);
}

Producto DetalleFactura::getProducto(){
    return this->producto;
}

float DetalleFactura::getValorSinIVA(){
    return this->valorSinIVA;
}

void DetalleFactura::setValorSinIVA(float valorSinIVA){
    this->valorSinIVA = valorSinIVA;
}

float DetalleFactura::getValorDelIVA(){
    return this->valorDelIVA;
}

void DetalleFactura::setValorDelIVA(float valorDelIVA){
    this->valorDelIVA = valorDelIVA;
}

float DetalleFactura::getValorTotal(){
    return this->valorTotal;
}

void DetalleFactura::setValorTotal(float valorTotal){
    this->valorTotal = valorTotal;
}

int DetalleFactura::getCantUnidVend(){
    return this->cantUnidVend;
}

void DetalleFactura::setCantUnidVend(int cantUnidVend){
    this->cantUnidVend = cantUnidVend;
}