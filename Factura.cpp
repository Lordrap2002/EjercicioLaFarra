#include "Factura.h"
#include <iostream>
#include <cstdio>

Factura::Factura(){
    this->fecha = "NA";
    this->codigo = 0;
    this->valorTotalSinIVA = this->valorTotalDelIVA = this->valorTotal = 0;
}

void Factura::mostrarFactura(){
    cout << "Codigo: " << this->codigo << ".\nFecha: " << this->fecha << ".\n";
    cout << "-----------------------------------------------------------\n" <<
           "Nombre del producto # Unidades Valor sin IVA Valor del IVA Valor Total\n" <<
           "=================== ========== ============= ============= ===========\n";
    for(vector<DetalleFactura>::iterator pDetalle = detalles.begin(); pDetalle != detalles.end(); pDetalle++){
        pDetalle->mostrarDetalle();
    }
    printf("=================== ========== ============= ============= ===========\n"
           "Totales                        %13f %13f %11f\n",
           this->valorTotalSinIVA, this->valorTotalDelIVA, this->valorTotal);
}
void Factura::agregarDetalle(DetalleFactura detalle){
    detalles.push_back(detalle);
}

vector<DetalleFactura> Factura::getDetalles(){
    return this->detalles;
}

void Factura::setFecha(string fecha){
    this->fecha = fecha;
}

string Factura::getFecha(){
   return this->fecha;
}

void Factura::setCodigo(int codigo){
    this->codigo = codigo;
}

int Factura::getCodigo(){
    return this->codigo;
}

void Factura::setValorTotalSinIVA(float valorTotalSinIVA){
    this->valorTotalSinIVA = valorTotalSinIVA;
}

float Factura::getValorTotalSinIVA(){
    return this->valorTotalSinIVA;
}

void Factura::setValorTotalDelIVA(float valorTotalDelIVA){
    this->valorTotalDelIVA = valorTotalDelIVA;
}

float Factura::getValorTotalDelIVA(){
    return this->valorTotalDelIVA;
}

void Factura::setValorTotal(float valorTotal){
    this->valorTotal = valorTotal;
}

float Factura::getValorTotal(){
    return this->valorTotal;
}
