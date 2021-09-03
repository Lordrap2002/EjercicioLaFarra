#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H

#include <iostream>
#include <stdlib.h>
#include "Producto.h"
#include <iomanip>

using std::cin;
using std::cout;
using std::string;

class DetalleFactura{
    private:
        Producto producto;
        int cantUnidVend;
        float valorSinIVA, valorDelIVA, valorTotal;

    public:
        DetalleFactura();
        DetalleFactura(Producto producto, int cantUnidVend, float valorSinIVA, float valorDelIVA, float valorTotal);
        void mostrarDetalle();
        void setProducto(Producto producto);
        Producto getProducto();
        void setValorSinIVA(float valorSinIVA);
        float getValorSinIVA();
        void setValorDelIVA(float valorDelIVA);
        float getValorDelIVA();
        void setValorTotal(float valorTotal);
        float getValorTotal();
        void setCantUnidVend(int cantUnidVend);
        int getCantUnidVend();
};

#endif