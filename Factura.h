#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <stdlib.h>
#include "DetalleFactura.h"
#include <vector>
#include <cstdio>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class Factura{
    private:
        string fecha;
        int codigo;
        float valorTotalSinIVA, valorTotalDelIVA, valorTotal;
        vector<DetalleFactura> detalles;
        
    public:
        Factura();
        void mostrarFactura();
        void agregarDetalle(DetalleFactura detalle);
        vector<DetalleFactura> getDetalles();
        void setFecha(string fecha);
        string getFecha();
        void setCodigo(int codigo);
        int getCodigo();
        void setValorTotalSinIVA(float valorTotalSinIVA);
        float getValorTotalSinIVA();
        void setValorTotalDelIVA(float valorTotalDelIVA);
        float getValorTotalDelIVA();
        void setValorTotal(float valorTotal);
        float getValorTotal();
};

#endif